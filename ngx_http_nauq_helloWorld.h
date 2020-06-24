//
// Created by nauq302 on 24/06/2020.
//

#ifndef NGX_HTTP_NAUQ_MODULE_NGX_HTTP_NAUQ_HELLOWORLD_H
#define NGX_HTTP_NAUQ_MODULE_NGX_HTTP_NAUQ_HELLOWORLD_H

#include "ngx_http_nauq_pch.h"


char* ngx_http_nauq_helloWorld(ngx_conf_t* cf, ngx_command_t* cmd, void* conf);
ngx_int_t ngx_http_nauq_helloWorld_handler(ngx_http_request_t* request);


#define ngx_nauq_http_helloWorld_command ((ngx_command_t) { \
        .name = ngx_string("nauq_helloWorld"),              \
        .type = NGX_HTTP_LOC_CONF | NGX_CONF_NOARGS,        \
        .set = ngx_http_nauq_helloWorld,                    \
        .conf = NGX_HTTP_LOC_CONF_OFFSET,                   \
        .offset = 0,                                        \
        .post = NULL                                        \
})

#endif //NGX_HTTP_NAUQ_MODULE_NGX_HTTP_NAUQ_HELLOWORLD_H
