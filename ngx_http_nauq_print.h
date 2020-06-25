//
// Created by nauq302 on 24/06/2020.
//

#ifndef NGX_HTTP_NAUQ_MODULE_NGX_HTTP_NAUQ_PRINT_H
#define NGX_HTTP_NAUQ_MODULE_NGX_HTTP_NAUQ_PRINT_H

#include "ngx_http_nauq_pch.h"

char* ngx_http_nauq_print(ngx_conf_t* cf, ngx_command_t* cmd, void* conf);
ngx_int_t ngx_http_nauq_print_handler(ngx_http_request_t* request);


#define ngx_nauq_http_print_command ((ngx_command_t) {  \
        .name = ngx_string("nauq_print"),               \
        .type = NGX_HTTP_LOC_CONF | NGX_CONF_TAKE1,     \
        .set = ngx_http_nauq_print,                     \
        .conf = NGX_HTTP_LOC_CONF_OFFSET,               \
        .offset = 0,                                    \
        .post = NULL                                    \
})


#endif //NGX_HTTP_NAUQ_MODULE_NGX_HTTP_NAUQ_PRINT_H
