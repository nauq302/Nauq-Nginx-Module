//
// Created by nauq302 on 24/06/2020.
//

#include "ngx_http_nauq_helloWorld.h"

char *ngx_http_nauq_helloWorld(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    ngx_http_core_loc_conf_t* clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
    clcf->handler = ngx_http_nauq_helloWorld_handler;

    return NGX_CONF_OK;
}

ngx_int_t ngx_http_nauq_helloWorld_handler(ngx_http_request_t *request)
{
    static ngx_str_t body = ngx_string("<h1>Hello World</h1>");

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
