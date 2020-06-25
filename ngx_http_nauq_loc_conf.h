//
// Created by nauq302 on 24/06/2020.
//

#ifndef NGX_HTTP_NAUQ_MODULE_NGX_HTTP_NAUQ_LOC_CONF_H
#define NGX_HTTP_NAUQ_MODULE_NGX_HTTP_NAUQ_LOC_CONF_H

#include "ngx_http_nauq_pch.h"

typedef struct ngx_http_nauq_loc_conf_t {
    ngx_str_t* printString;
} ngx_http_nauq_loc_conf_t;

void* ngx_http_nauq_create_loc_conf(ngx_conf_t* cf);
char* ngx_http_nauq_merge_loc_conf(ngx_conf_t* cf, void* parent, void* child);

#endif //NGX_HTTP_NAUQ_MODULE_NGX_HTTP_NAUQ_LOC_CONF_H
