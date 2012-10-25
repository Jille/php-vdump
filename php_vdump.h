/*
   +----------------------------------------------------------------------+
   | Authors: Jille Timmermans <jille@hexon.cx>                           |
   +----------------------------------------------------------------------+
*/

/* $ Id: $ */ 

#ifndef PHP_VDUMP_H
#define PHP_VDUMP_H

#include "php.h"
#include "ext/standard/php_string.h"
#include <stdio.h>

#ifdef  __cplusplus
extern "C" {
#endif

struct vdump {
	FILE *fh;
	zval references;
};

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#ifdef HAVE_VDUMP
#define PHP_VDUMP_VERSION "0.1"


#include <php_ini.h>
#include <SAPI.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#ifdef  __cplusplus
} // extern "C" 
#endif
#ifdef  __cplusplus
extern "C" {
#endif

extern zend_module_entry vdump_module_entry;
#define phpext_vdump_ptr &vdump_module_entry

#ifdef PHP_WIN32
#define PHP_VDUMP_API __declspec(dllexport)
#else
#define PHP_VDUMP_API
#endif

PHP_MINFO_FUNCTION(vdump);

#ifdef ZTS
#include "TSRM.h"
#endif

#define FREE_RESOURCE(resource) zend_list_delete(Z_LVAL_P(resource))

#define PROP_GET_LONG(name)    Z_LVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_LONG(name, l) zend_update_property_long(_this_ce, _this_zval, #name, strlen(#name), l TSRMLS_CC)

#define PROP_GET_DOUBLE(name)    Z_DVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_DOUBLE(name, d) zend_update_property_double(_this_ce, _this_zval, #name, strlen(#name), d TSRMLS_CC)

#define PROP_GET_STRING(name)    Z_STRVAL_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_GET_STRLEN(name)    Z_STRLEN_P(zend_read_property(_this_ce, _this_zval, #name, strlen(#name), 1 TSRMLS_CC))
#define PROP_SET_STRING(name, s) zend_update_property_string(_this_ce, _this_zval, #name, strlen(#name), s TSRMLS_CC)
#define PROP_SET_STRINGL(name, s, l) zend_update_property_stringl(_this_ce, _this_zval, #name, strlen(#name), s, l TSRMLS_CC)


PHP_FUNCTION(vdump_dump);

ZEND_BEGIN_ARG_INFO_EX(vdump_dump_arg_info, ZEND_SEND_BY_VAL, ZEND_RETURN_VALUE, 1)
  ZEND_ARG_INFO(0, outfile)
ZEND_END_ARG_INFO()

#ifdef  __cplusplus
} // extern "C" 
#endif

#endif /* PHP_HAVE_VDUMP */

#endif /* PHP_VDUMP_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
