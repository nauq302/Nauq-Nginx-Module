#include "ngx_http_nauq_module.h"

#include "ngx_http_nauq_helloWorld.h"

ngx_command_t ngx_http_nauq_commands[] = {
        ngx_nauq_http_helloWorld_command,
        ngx_null_command
};

ngx_http_module_t ngx_http_nauq_module_ctx = {
        .preconfiguration = NULL,
        .postconfiguration = NULL,

        .create_main_conf = NULL,
        .init_main_conf = NULL,

        .create_srv_conf = NULL,
        .merge_srv_conf = NULL,

        .create_loc_conf = NULL,
        .merge_loc_conf = NULL
};


ngx_module_t ngx_http_nauq_module = {
        NGX_MODULE_V1,
        .ctx = &ngx_http_nauq_module_ctx,
        .commands = ngx_http_nauq_commands,
        .type = NGX_HTTP_MODULE,
        .init_master = NULL,
        .init_module = NULL,
        .init_process = NULL,
        .init_thread = NULL,
        .exit_thread = NULL,
        .exit_process = NULL,
        .exit_master = NULL,
        NGX_MODULE_V1_PADDING
};