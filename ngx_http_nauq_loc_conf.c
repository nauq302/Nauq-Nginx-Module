//
// Created by nauq302 on 24/06/2020.
//
#include "ngx_http_nauq_loc_conf.h"
#include <stdio.h>

void* ngx_http_nauq_create_loc_conf(ngx_conf_t* cf)
{
    ngx_http_nauq_loc_conf_t* conf = ngx_pcalloc(cf->pool, sizeof(ngx_http_nauq_loc_conf_t));

    if (conf == NULL) {
        ngx_conf_log_error(NGX_LOG_EMERG, cf, 0, "NULL conf");
        return NGX_CONF_ERROR;

    } else {
        conf->printString = NGX_CONF_UNSET_PTR;
        return conf;
    }
}

char* ngx_http_nauq_merge_loc_conf(ngx_conf_t* cf, void* parent, void* child)
{
    ngx_http_nauq_loc_conf_t* prev = parent;
    ngx_http_nauq_loc_conf_t* conf = child;

    ngx_conf_merge_ptr_value(conf->printString, prev->printString, ngx_pcalloc(cf->pool, sizeof(ngx_str_t)));

    return NGX_CONF_OK;
}
