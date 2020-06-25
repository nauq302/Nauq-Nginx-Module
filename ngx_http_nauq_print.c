//
// Created by nauq302 on 24/06/2020.
//

#include "ngx_http_nauq_print.h"
#include "ngx_http_nauq_loc_conf.h"
#include "ngx_http_nauq_module.h"

char* ngx_http_nauq_print(ngx_conf_t* cf, ngx_command_t* cmd, void* conf)
{
    ngx_http_core_loc_conf_t* clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_nauq_print_handler;

    ngx_str_t* args = cf->args->elts;

    ngx_http_nauq_loc_conf_t* nauqLocConf = conf;
    nauqLocConf->printString = &args[1];



    return NGX_CONF_OK;
}



ngx_int_t ngx_http_nauq_print_handler(ngx_http_request_t* request)
{
    ngx_http_nauq_loc_conf_t* conf = ngx_http_get_module_loc_conf(request, ngx_http_nauq_module);
    ngx_str_t body = *conf->printString;

    request->headers_out.content_type = (ngx_str_t) ngx_string("text/html");
    request->headers_out.status = NGX_HTTP_OK;
    request->headers_out.content_length_n = body.len;

    ngx_buf_t* buffer = ngx_pcalloc(request->pool, sizeof(ngx_buf_t));
    ngx_chain_t out = { .buf = buffer, .next = NULL };

    buffer->pos = body.data;
    buffer->last = body.data + body.len;
    buffer->memory = true;
    buffer->last_buf = true;

    ngx_http_send_header(request);

    return ngx_http_output_filter(request, &out);
}