#include "quad.h"
#include "ast.h"
#include "symtab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
extern blockss blocks;
extern symtab* symtab_file;
char* getStoredRegister(int* allocator, int tempnum);
char* getNewRegister(int* allocator, int tempnum);
extern FILE* f;
/*
	.file	"printing.c"
	.text
	.globl	fib
	.type	fib, @function
fib:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	%edi, -20(%rbp)
	cmpl	$1, -20(%rbp)
	jg	.L2
	movl	$1, %eax
	jmp	.L3
.L2:
	movl	-20(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %edi
	call	fib
	movl	%eax, %ebx
	movl	-20(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %edi
	call	fib
	addl	%ebx, %eax
.L3:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	fib, .-fib
	.section	.rodata
.LC0:
	.string	"fibonacci"
.LC1:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$8, %edi
	call	fib
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Alpine 12.2.1_git20220924-r10) 12.2.1 20220924"
	.section	.note.GNU-stack,"",@progbits

*/
void generate(char* filename) {
    f = fopen(filename,"w");
    fprintf(f,".file \"%s\"\n",filename);
    int i;
    for(i=0;i<symtab_file->rownum;i++) {
        symrec rec = symtab_file->row[i];
        if (rec.symtype == SYM_FUNC) {
            fprintf(f,".text \n");
            fprintf(f,".globl %s\n",rec.ident);
            fprintf(f,".type %s, @function\n",rec.ident);
        } else if (rec.symtype == SYM_VAR) {
            if (rec.type->head->next->value->nodetype == AST_TYPE && rec.type->head->next->value->type->stg == STG_NONE) {
                fprintf(f,".text \n");
                fprintf(f,".globl %s\n",rec.ident);
                fprintf(f,".bss\n",rec.ident);
                fprintf(f,".align %d\n",typeSize(rec.type->head->next));
                fprintf(f,".size %d\n",typeSize(rec.type->head->next));
                fprintf(f,".type %s, @object\n",rec.ident);
                fprintf(f,"%s:\n",rec.ident);
                fprintf(f,".zero %d\n",typeSize(rec.type->head->next));
            } else if (rec.type->head->next->value->nodetype == AST_TYPE && rec.type->head->next->value->type->stg == STG_STATIC) {
                fprintf(f,".text \n");
                fprintf(f,".local %s\n",rec.ident);
                fprintf(f,".comm %s,%d,%d\n",rec.ident,typeSize(rec.type->head->next),typeSize(rec.type->head->next));
            }
        }
    }
    //allocator:
    int allocator[3] = {-1,-1,-1};
    for(i=0;i<blocks.len;i++) {
        block* b = &blocks.blocks[i];
        printf("%d\n",b);
        int funcc = 0;
        printf("%d\n",funcc);
        if (b->sym) {
            fprintf(f,"%s:\n",b->sym->ident);
            funcc=1;
        }
        fprintf(f,".BB%d:\n",b->id);
        if (funcc) {
            fprintf(f,"pushq %%rbp\n");
            fprintf(f,"movq %%rsp, %%rbp\n");
            fprintf(f,"subq %%%d, %%rsp\n",b->sym->func->localtotal * 8);
            funcc = 0;
        }
        int j=0;
        for(j;j<b->q.len;j++) {
            quad q = b->q.quads[j];
            int a=0;
            int b=0;
            int c_=0;
            int aa=0;
            int bb=0;
            int cc=0;
            if (q.src1 && q.src1->nodetype == AST_IDENT) {
                a=rbpOffset(q.src1);
                if (a == -1) aa=3; //global
                else aa=1; //on stack
            } else if (q.src1 && q.src1->nodetype == AST_TEMPORARY){
                aa=2; //temp var
            } //else means a is an ast_num
            if (q.src2 && q.src2->nodetype == AST_IDENT) {
                b=rbpOffset(q.src2);
                if (b == -1) bb=3;
                else bb=1;
            } else if (q.src2 && q.src2->nodetype == AST_TEMPORARY){
                bb=2;
            }
            if (q.dest && q.dest->nodetype == AST_IDENT) {
                c_=rbpOffset(q.dest);
                if(c_ == -1) cc=3;
                else cc=1;
            } else if (q.dest && q.dest->nodetype == AST_TEMPORARY){
                cc=2;
            }
            char *c,*d,*e;
            switch (q.opcode) {
                case q_add:
                    if (aa != 2) c = getNewRegister(allocator,-2);
                    if (aa==1) fprintf(f,"movq %d(%%rbp), %%%s\n",a,c);
                    else if (aa==0) fprintf(f,"movq $%d, %%%s\n",q.src1->num->i,c);
                    else if (aa==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,c);
                    else c = getStoredRegister(allocator,q.src1->tempnum);
                    if (bb != 2) d = getNewRegister(allocator,-3);
                    if (bb==1) fprintf(f,"movq %d(%%rbp), %%%s\n",b,d);
                    else if (bb==0) fprintf(f,"movq $%d, %%%s\n",q.src2->num->i,d);
                    else if (bb==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src2->ident->name,d);
                    else d = getStoredRegister(allocator,q.src2->tempnum);
                    fprintf(f,"addq %%%s, %%%s\n",c,d);
                    deallocate(allocator,-2);
                    deallocate(allocator,-3);
                    deallocate(allocator,q.src1->tempnum);
                    deallocate(allocator,q.src2->tempnum);
                    if (cc == 2) e = getNewRegister(allocator,q.dest->tempnum);
                    if (cc==1) fprintf(f,"movl %%%s, %d(%%rbp)\n",d,rbpOffset(q.dest->ident));
                    else if (cc==3) fprintf(f,"movl %%%s, %s(%%rip)\n",d,q.dest->ident->name);
                    else fprintf(f,"movq %%%s, %%%s\n",d,e);
                break;
                case q_sub:
                    if (aa != 2) c = getNewRegister(allocator,-2);
                    if (aa==1) fprintf(f,"movq %d(%%rbp), %%%s\n",a,c);
                    else if (aa==0) fprintf(f,"movq $%d, %%%s\n",q.src1->num->i,c);
                    else if (aa==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,c);
                    else c = getStoredRegister(allocator,q.src1->tempnum);
                    if (bb != 2) d = getNewRegister(allocator,-3);
                    if (bb==1) fprintf(f,"movq %d(%%rbp), %%%s\n",b,d);
                    else if (bb==0) fprintf(f,"movq $%d, %%%s\n",q.src2->num->i,d);
                    else if (bb==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src2->ident->name,d);
                    else d = getStoredRegister(allocator,q.src2->tempnum);
                    fprintf(f,"subq %%%s, %%%s\n",c,d);
                    deallocate(allocator,-2);
                    deallocate(allocator,-3);
                    deallocate(allocator,q.src1->tempnum);
                    deallocate(allocator,q.src2->tempnum);
                    if (cc == 2) e = getNewRegister(allocator,q.dest->tempnum);
                    if (cc==1) fprintf(f,"movl %%%s, %d(%%rbp)\n",d,rbpOffset(q.dest->ident));
                    else if (cc==3) fprintf(f,"movl %%%s, %s(%%rip)\n",d,q.dest->ident->name);
                    else fprintf(f,"movq %%%s, %%%s\n",d,e);
                break;
                case q_mul:
                    if (aa != 2) c = getNewRegister(allocator,-2);
                    else c = getStoredRegister(allocator,q.src1->tempnum);
                    if (strcmp(c,"rax") != 0) {
                        int t = allocator[0];
                        allocator[0] = strcmp(c,"r10") == 0 ? allocator[1] : allocator[2];
                        if (strcmp(c,"r10") == 0)
                            allocator[1] = t;
                        else
                            allocator[2] = t;
                    }
                    if (aa==1) fprintf(f,"movq %d(%%rbp), %%%s\n",a,c);
                    else if (aa==0) fprintf(f,"movq $%d, %%%s\n",q.src1->num->i,c);
                    else if (aa==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,c);
                    if (bb != 2) d = getNewRegister(allocator,-3);
                    if (bb==1) fprintf(f,"movq %d(%%rbp), %%%s\n",b,d);
                    else if (bb==0) fprintf(f,"movq $%d, %%%s\n",q.src2->num->i,d);
                    else if (bb==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src2->ident->name,d);
                    else d = getStoredRegister(allocator,q.src2->tempnum);
                    fprintf(f,"mulq %%%s\n",c);
                    deallocate(allocator,-2);
                    deallocate(allocator,-3);
                    deallocate(allocator,q.src1->tempnum);
                    deallocate(allocator,q.src2->tempnum);
                    if (cc == 2) e = getNewRegister(allocator,q.dest->tempnum);
                    if (cc==1) fprintf(f,"movl %%%s, %d(%%rbp)\n",c,rbpOffset(q.dest->ident));
                    else if (cc==3) fprintf(f,"movl %%%s, %s(%%rip)\n",c,q.dest->ident->name);
                    else fprintf(f,"movq %%%s, %%%s\n",c,e);
                break;
                case q_div:
                    if (aa != 2) c = getNewRegister(allocator,-2);
                    else c = getStoredRegister(allocator,q.src1->tempnum);
                    if (strcmp(c,"rax") != 0) {
                        int t = allocator[0];
                        allocator[0] = strcmp(c,"r10") == 0 ? allocator[1] : allocator[2];
                        if (strcmp(c,"r10") == 0)
                            allocator[1] = t;
                        else
                            allocator[2] = t;
                    }
                    if (aa==1) fprintf(f,"movq %d(%%rbp), %%%s\n",a,c);
                    else if (aa==0) fprintf(f,"movq $%d, %%%s\n",q.src1->num->i,c);
                    else if (aa==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,c);
                    if (bb != 2) d = getNewRegister(allocator,-3);
                    if (bb==1) fprintf(f,"movq %d(%%rbp), %%%s\n",b,d);
                    else if (bb==0) fprintf(f,"movq $%d, %%%s\n",q.src2->num->i,d);
                    else if (bb==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src2->ident->name,d);
                    else d = getStoredRegister(allocator,q.src2->tempnum);
                    fprintf(f,"divq %%%s\n",c);
                    deallocate(allocator,-2);
                    deallocate(allocator,-3);
                    deallocate(allocator,q.src1->tempnum);
                    deallocate(allocator,q.src2->tempnum);
                    if (cc == 2) e = getNewRegister(allocator,q.dest->tempnum);
                    if (cc==1) fprintf(f,"movl %%%s, %d(%%rbp)\n",c,rbpOffset(q.dest->ident));
                    else if (cc==3) fprintf(f,"movl %%%s, %s(%%rip)\n",c,q.dest->ident->name);
                    else fprintf(f,"movq %%%s, %%%s\n",c,e);
                break;
                case q_mov:
                    if (aa==0) {
                        if (cc==1) {
                            fprintf(f,"movl $%d, %d(%%rbp)\n",q.src1->num->i,c_);
                        }else if (cc==3) {
                            fprintf(f,"movl $%d, %s(%%rip)\n",q.src1->num->i,q.dest->ident->name);
                        } else {
                            fprintf(f,"movq $%d, %%%s\n",q.src1->num->i,getNewRegister(allocator,q.dest->tempnum));
                        }
                    } else if (aa==1){
                        if (cc==1) {
                            fprintf(f,"movq %d(%%rbp), %%%s\n",a,getNewRegister(allocator,-2));
                            fprintf(f,"movl %%%s, %d(%%rbp)\n",getStoredRegister(allocator,-2),c_);
                            deallocate(allocator,-2);
                        } else if (cc==3) {
                            fprintf(f,"movq %d(%%rbp), %%%s\n",a,getNewRegister(allocator,-2));
                            fprintf(f,"movl %%%s, %s(%%rip)\n",getStoredRegister(allocator,-2),q.dest->ident->name);
                            deallocate(allocator,-2);
                        }  else {
                            fprintf(f,"movq %d(%%rbp), %%%s\n",a,getNewRegister(allocator,q.dest->tempnum));
                        }
                    } else if (aa==2){
                        if (cc==1) {
                            fprintf(f,"movl %%%s, %d(%%rbp)\n",getStoredRegister(allocator,q.src1->tempnum),c_);
                            deallocate(allocator,q.src1->tempnum);
                        } else if (cc==3) {
                            fprintf(f,"movl %%%s, %s(%%rip)\n",getStoredRegister(allocator,q.src1->tempnum),q.dest->ident->name);
                            deallocate(allocator,q.src1->tempnum);
                        }  else {
                            fprintf(f,"movq %%%s, %%%s\n",getStoredRegister(allocator,q.src1->tempnum),getNewRegister(allocator,q.dest->tempnum));
                            deallocate(allocator,q.src1->tempnum);
                        }
                    } else if (aa==3){
                        if (cc==1) {
                            fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,getNewRegister(allocator,-2));
                            fprintf(f,"movl %%%s, %d(%%rbp)\n",getStoredRegister(allocator,-2),c_);
                            deallocate(allocator,-2);
                        } else if (cc==3) {
                            fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,getNewRegister(allocator,-2));
                            fprintf(f,"movl %%%s, %s(%%rip)\n",getStoredRegister(allocator,-2),q.dest->ident->name);
                            deallocate(allocator,-2);
                        }  else {
                            fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,getNewRegister(allocator,q.dest->tempnum));
                        }
                    }
                    break;
                case q_lea:
                    if (aa==1) {
                        if(cc==1) {
                            fprintf(f,"leaq %d(%%rbp), %%%s\n",a,getNewRegister(allocator,-2));
                            fprintf(f,"movl %%%s, %d(%%rbp)\n",getStoredRegister(allocator,-2),c_);
                            deallocate(allocator,-2);
                        } else if (cc==2) {
                            fprintf(f,"leaq %d(%%rbp), %%%s\n",a,getNewRegister(allocator,q.dest->tempnum));
                        } else if (cc==3) {
                            fprintf(f,"leaq %d(%%rbp), %%%s\n",a,getNewRegister(allocator,-2));
                            fprintf(f,"movl %%%s, %s(%%rip)\n",getStoredRegister(allocator,-2),q.dest->ident->name);
                            deallocate(allocator,-2);
                        }
                    } else if (aa==2) {
                        if(cc==1) {
                            fprintf(f,"leaq %%%s, %d(%%rbp)\n",getStoredRegister(allocator,q.src1->ident->name),c_);
                            deallocate(allocator,q.src1->ident->name);
                        } else if (cc==2) {
                            reallocate(allocator,q.src1->tempnum,q.dest->tempnum);
                        } else if (cc==3) {
                            fprintf(f,"leaq %s(%%rip), %%%s\n",q.src1->ident->name,getNewRegister(allocator,-2));
                            fprintf(f,"movl %%%s, %s(%%rip)\n",getStoredRegister(allocator,-2),q.dest->ident->name);
                            deallocate(allocator,-2);
                        }
                    } else if (aa==3) {
                        if(cc==1) {
                            fprintf(f,"leaq %s(%%rip), %%%s\n",q.src1->ident->name,getNewRegister(allocator,-2));
                            fprintf(f,"movl %%%s, %d(%%rbp)\n",getStoredRegister(allocator,-2),c_);
                            deallocate(allocator,-2);
                        } else if (cc==2) {
                            fprintf(f,"leaq %s(%%rip), %%%s\n",q.src1->ident->name,getNewRegister(allocator,q.dest->tempnum));
                        } else if (cc==3) {
                            fprintf(f,"leaq %s(%%rip), %%%s\n",q.src1->ident->name,getNewRegister(allocator,-2));
                            fprintf(f,"movl %%%s, %s(%%rip)\n",getStoredRegister(allocator,-2),q.dest->ident->name);
                            deallocate(allocator,-2);
                        }
                    }
                    break;
                case q_store:
                    if (aa==1) {
                        fprintf(f,"movq %d(%%rbp), %%%s\n",a,getNewRegister(allocator,-2));
                        fprintf(f,"movl %%%s, (%%%s)\n",getStoredRegister(allocator,-2),getStoredRegister(allocator,q.dest->tempnum));
                        deallocate(allocator,-2);
                    } else if (aa==2) {
                        fprintf(f,"movl %%%s, (%%%s)\n",getStoredRegister(allocator,q.src1->tempnum),getStoredRegister(allocator,q.dest->tempnum));
                        deallocate(allocator,q.src1->tempnum);
                    } else if (aa==3) {
                        fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,getNewRegister(allocator,-2));
                        fprintf(f,"movl %%%s, (%%%s)\n",getStoredRegister(allocator,-2),getStoredRegister(allocator,q.dest->tempnum));
                        deallocate(allocator,-2);
                    }
                    break;
                case q_load:
                    if (aa == 1) {
                        fprintf(f,"movq %d(%%rbp), %%%s\n",a,getNewRegister(allocator,q.dest->tempnum));
                        fprintf(f,"movq (%%%s), %%%s\n",getStoredRegister(allocator,q.dest->tempnum),getStoredRegister(allocator,q.dest->tempnum));
                    } else if (aa == 2) {
                        fprintf(f,"movq (%%%s), %%%s\n",getStoredRegister(allocator,q.src1->tempnum),getStoredRegister(allocator,q.src1->tempnum));
                        reallocate(allocator,q.src1->tempnum,q.dest->tempnum);
                    } else if (aa == 3) {
                        fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,getNewRegister(allocator,q.dest->tempnum));
                        fprintf(f,"movq (%%%s), %%%s\n",getStoredRegister(allocator,q.dest->tempnum),getStoredRegister(allocator,q.dest->tempnum));
                    }
                    break;
                case q_storestack:
                    if (aa == 0){
                        fprintf(f,"pushl $%d\n",q.src1->num->i);
                    } else if (aa == 1) {
                        fprintf(f,"pushl %d(%%rbp)\n",a);
                    } else if (aa == 2) {
                        fprintf(f,"pushl %%%s\n",getStoredRegister(allocator,q.src1->tempnum));
                        deallocate(allocator,q.src1->tempnum);
                    } else {
                        fprintf(f,"pushl %s(%%rip)\n",q.src1->ident->name);
                    }
                    break;
                case q_call:
                {
                    symrec* rec = findsym(symtab_file,q.src1->ident->name,NAMESPACE_OTHERS);
                    fprintf(f,"movq %%rax %%r12\n");
                    fprintf(f,"movq %%r10 %%r13\n");
                    if (rec) fprintf(f,"call %s\n",rec->ident);
                    else fprintf(f,"call %s@PLT\n",q.src1->ident->name);   
                    allocator[2] = allocator[1];
                    allocator[1] = allocator[0];
                    if (cc==1) {
                        fprintf(f,"movq %%rax %d(%%rbp)\n",a);
                    } else if (cc==2) {
                        allocator[0] = q.dest->tempnum;
                    } else if (cc==3) {
                        fprintf(f,"movq %%rax %s(%%rip)\n",q.dest->ident->name);
                    }
                    fprintf(f,"movq %%r12 %%r10\n");
                    fprintf(f,"movq %%r13 %%r11\n");
                }
                break;
                case q_rt:
                    if (aa==0) {
                        fprintf(f,"movl $%d\n",q.src1->num->i);
                    } else if (aa==2) {
                        fprintf(f,"movq %%%%s %%rax\n",getStoredRegister(allocator,q.src1->tempnum));
                    } else if (aa=1) {
                        fprintf(f,"movq %d(%%rbp), %%rax\n",a);
                    } else {
                        fprintf(f,"movq %s(%%rip), %%rax\n",q.src1->ident->name);
                    }
                    fprintf(f,"leave\n");
                    fprintf(f,"ret\n");
                break;
                case q_cmp:
                    if (aa != 2) c = getNewRegister(allocator,-2);
                    if (aa==1) fprintf(f,"movq %d(%%rbp), %%%s\n",a,c);
                    else if (aa==0) fprintf(f,"movq $%d, %%%s\n",q.src1->num->i,c);
                    else if (aa==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src1->ident->name,c);
                    else c = getStoredRegister(allocator,q.src1->tempnum);
                    if (bb != 2) d = getNewRegister(allocator,-3);
                    if (bb==1) fprintf(f,"movq %d(%%rbp), %%%s\n",b,d);
                    else if (bb==0) fprintf(f,"movq $%d, %%%s\n",q.src2->num->i,d);
                    else if (bb==3) fprintf(f,"movq %s(%%rip), %%%s\n",q.src2->ident->name,d);
                    else d = getStoredRegister(allocator,q.src2->tempnum);
                    fprintf(f,"cmp %%%s, %%%s\n",c,d);
                    deallocate(allocator,-2);
                    deallocate(allocator,-3);
                    deallocate(allocator,q.src1->tempnum);
                    deallocate(allocator,q.src2->tempnum);
                    break;
                case q_br:
                    fprintf(f,"jmp .BB%d\n",q.dest->num->i);
                    break;
                case q_gt:
                    fprintf(f,"jg .BB%d\n",q.src1->num->i);
                    fprintf(f,"jle .BB%d\n",q.src2->num->i);
                    break;
                case q_ge:
                    fprintf(f,"jge .BB%d\n",q.src1->num->i);
                    fprintf(f,"jl .BB%d\n",q.src2->num->i);
                    break;
                case q_lt:
                    fprintf(f,"jl .BB%d\n",q.src1->num->i);
                    fprintf(f,"jge .BB%d\n",q.src2->num->i);
                    break;
                case q_le:
                    fprintf(f,"jle .BB%d\n",q.src1->num->i);
                    fprintf(f,"jg .BB%d\n",q.src2->num->i);
                    break;
                case q_eq:
                    fprintf(f,"je .BB%d\n",q.src1->num->i);
                    fprintf(f,"jne .BB%d\n",q.src2->num->i);
                    break;
                case q_ne:
                    fprintf(f,"jne .BB%d\n",q.src1->num->i);
                    fprintf(f,"je .BB%d\n",q.src2->num->i);
                    break;
            }   
        }
    }
    fclose(f);
}

void deallocate(int* allocator, int tempnum){
    if(tempnum == allocator[0]) allocator[0] = -1;
    else if (tempnum == allocator[1]) allocator[1] = -1;
    else if (tempnum == allocator[2]) allocator[2] = -1;
}

char* getNewRegister(int* allocator, int tempnum) {
    if (allocator[0] == -1) {allocator[0] = tempnum; return "rax";}
    else if (allocator[1] == -1) {allocator[1] = tempnum; return "r10";}
    else if (allocator[2] == -1) {allocator[2] = tempnum; return "r11";}
    else return "error";
}

char* getStoredRegister(int* allocator, int tempnum) {
    if (allocator[0] == tempnum) return "rax";
    else if (allocator[1] == tempnum) return "r10";
    else if (allocator[2] == tempnum) return "r11";
    else return "error";
}

void reallocate(int* allocator, int tempnum, int destnum) {
    if (allocator[0] == tempnum) allocator[0] = destnum;
    else if (allocator[1] == tempnum) allocator[1] = destnum;
    else if (allocator[2] == tempnum) allocator[2] = destnum;
}

int rbpOffset(astnode* ident) {
    symtab* tbl = ident->tbl;
    if (!tbl){
        fprintf(stderr,"critical error: ident %s not found because symbol table does not exist (code gen)\n",ident->ident->name);
        return -1;
    } else {
        int i=0;
        int offset = 8;
        symrec* rec = findsym(tbl,ident->ident->name,NAMESPACE_OTHERS);
        if (rec) {
            if (rec->symtype == SYM_PROTOVAR) {
                return offset + (rec->index-1)*8;
            } else if (rec->symtype == SYM_VAR) {
                return -(rec->index)*8;
            }
        }
        return -1;
    }
}