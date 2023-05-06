FROM alpine:latest
RUN apk update; apk add flex; apk add bison; apk add --no-cache bash; apk add gcc; apk add musl-dev; apk add make; apk add gdb
CMD ["/bin/sh"]