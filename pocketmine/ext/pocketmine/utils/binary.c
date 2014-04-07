
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PocketMine_Utils_Binary) {

	ZEPHIR_REGISTER_CLASS(PocketMine\\Utils, Binary, pocketmine, utils_binary, pocketmine_utils_binary_method_entry, 0);

	zend_declare_class_constant_long(pocketmine_utils_binary_ce, SL("BIG_ENDIAN"), 0x00 TSRMLS_CC);

	zend_declare_class_constant_long(pocketmine_utils_binary_ce, SL("LITTLE_ENDIAN"), 0x01 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PocketMine_Utils_Binary, readTriad) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *str_param = NULL, _0, _1, *_2 = NULL, *_4;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "N", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "\x00", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "unpack", &_3, &_0, &_1, str);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, _2, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTOR(_4);

}

PHP_METHOD(PocketMine_Utils_Binary, writeTriad) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zval *value_param = NULL, _0 = zval_used_for_init, _1, *_2 = NULL;
	long value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_intval(value_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "N", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, value);
	ZEPHIR_CALL_FUNCTION(&_2, "pack", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("substr", &_4, _2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Utils_Binary, writeMetadata) {

	zephir_fcall_cache_entry *_9 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *m;
	zval *data_param = NULL, *bottom = NULL, *d = NULL, **_2, *_3, _4 = zval_used_for_init, *_5 = NULL, *_7, *_8 = NULL, *_10, *_14, *_15 = NULL, *_16 = NULL, *_17, *_18, *_19 = NULL, *_20, *_21;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);
	ZEPHIR_INIT_VAR(m);
	ZVAL_STRING(m, "", 1);


	zephir_is_iterable(data, &_1, &_0, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(bottom, _1, _0);
		ZEPHIR_GET_HVALUE(d, _2);
		zephir_array_fetch_long(&_3, d, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_LONG(&_4, (((zephir_get_numberval(_3) * 32)) + (((int) (zephir_get_numberval(bottom)) & 0x1f))));
		ZEPHIR_CALL_FUNCTION(&_5, "chr", &_6, &_4);
		zephir_check_call_status();
		zephir_concat_self(&m, _5 TSRMLS_CC);
		zephir_array_fetch_long(&_7, d, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_7, 0)) {
				zephir_array_fetch_long(&_10, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_8, "writebyte", &_9, _10);
				zephir_check_call_status();
				zephir_concat_self(&m, _8 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_7, 1)) {
				zephir_array_fetch_long(&_10, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_8, "writelshort", &_11, _10);
				zephir_check_call_status();
				zephir_concat_self(&m, _8 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_7, 2)) {
				zephir_array_fetch_long(&_10, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_8, "writelint", &_12, _10);
				zephir_check_call_status();
				zephir_concat_self(&m, _8 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_7, 3)) {
				zephir_array_fetch_long(&_10, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_8, "writelfloat", &_13, _10);
				zephir_check_call_status();
				zephir_concat_self(&m, _8 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_7, 4)) {
				zephir_array_fetch_long(&_10, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_8, "writelshort", &_11, _10);
				zephir_check_call_status();
				zephir_array_fetch_long(&_14, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_INIT_LNVAR(_15);
				ZEPHIR_CONCAT_VV(_15, _8, _14);
				zephir_concat_self(&m, _15 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_7, 5)) {
				zephir_array_fetch_long(&_10, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_long(&_14, _10, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_8, "writelshort", &_11, _14);
				zephir_check_call_status();
				zephir_concat_self(&m, _8 TSRMLS_CC);
				zephir_array_fetch_long(&_17, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_long(&_18, _17, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_16, "writebyte", &_9, _18);
				zephir_check_call_status();
				zephir_concat_self(&m, _16 TSRMLS_CC);
				zephir_array_fetch_long(&_20, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_long(&_21, _20, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_19, "writelshort", &_11, _21);
				zephir_check_call_status();
				zephir_concat_self(&m, _19 TSRMLS_CC);
				break;
			}
			if (ZEPHIR_IS_LONG(_7, 6)) {
				zephir_array_fetch_long(&_10, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_long(&_14, _10, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_8, "writelint", &_12, _14);
				zephir_check_call_status();
				zephir_concat_self(&m, _8 TSRMLS_CC);
				zephir_array_fetch_long(&_17, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_long(&_18, _17, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_16, "writelint", &_12, _18);
				zephir_check_call_status();
				zephir_concat_self(&m, _16 TSRMLS_CC);
				zephir_array_fetch_long(&_20, d, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
				zephir_array_fetch_long(&_21, _20, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
				ZEPHIR_CALL_SELF(&_19, "writelint", &_12, _21);
				zephir_check_call_status();
				zephir_concat_self(&m, _19 TSRMLS_CC);
				break;
			}
		} while(0);

	}
	ZEPHIR_CONCAT_VS(return_value, m, "\x7f");
	RETURN_MM();

}

PHP_METHOD(PocketMine_Utils_Binary, readMetadata) {

	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL, *_10 = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_8 = NULL, *_11 = NULL, *_12 = NULL;
	char _0, _2, _4;
	int bottom, type, ZEPHIR_LAST_CALL_STATUS;
	unsigned char b;
	zval *m, *_18 = NULL;
	long offset = 1;
	zend_bool types, _1;
	zval *value_param = NULL, *types_param = NULL, *r = NULL, *len = NULL, _5 = zval_used_for_init, *_6 = NULL, _9 = zval_used_for_init, *_13 = NULL, *_14 = NULL, *_15 = NULL, *_16 = NULL, *_17 = NULL, *_19 = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value_param, &types_param);

	zephir_get_strval(value, value_param);
	if (!types_param) {
		types = 1;
	} else {
		types = zephir_get_boolval(types_param);
	}
	ZEPHIR_INIT_VAR(m);
	array_init(m);


	_0 = ZEPHIR_STRING_OFFSET(value, 0);
	b = _0;
	while (1) {
		_1 = b != 127;
		if (_1) {
			_2 = ZEPHIR_STRING_OFFSET(value, offset);
			_1 = _2 != 0;
		}
		if (!(_1)) {
			break;
		}
		bottom = (b & 0x1f);
		type = (((b & 0xe0)) / 32);
		do {
			if (type == 0) {
				_4 = ZEPHIR_STRING_OFFSET(value, offset);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, _4);
				ZEPHIR_CALL_FUNCTION(&_6, "ord", &_7, &_5);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&r, "readbyte", &_3, _6);
				zephir_check_call_status();
				offset++;
				break;
			}
			if (type == 1) {
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 2);
				ZEPHIR_CALL_FUNCTION(&_6, "substr", &_10, value, &_5, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&r, "readlshort", &_8, _6);
				zephir_check_call_status();
				offset += 2;
				break;
			}
			if (type == 2) {
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 4);
				ZEPHIR_CALL_FUNCTION(&_6, "substr", &_10, value, &_5, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&r, "readlint", &_11, _6);
				zephir_check_call_status();
				offset += 4;
				break;
			}
			if (type == 3) {
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 4);
				ZEPHIR_CALL_FUNCTION(&_6, "substr", &_10, value, &_5, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&r, "readlfloat", &_12, _6);
				zephir_check_call_status();
				offset += 4;
				break;
			}
			if (type == 4) {
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 2);
				ZEPHIR_CALL_FUNCTION(&_6, "substr", &_10, value, &_5, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&len, "readlshort", &_8, _6);
				zephir_check_call_status();
				offset += 2;
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_CALL_FUNCTION(&r, "substr", &_10, value, &_5, len);
				zephir_check_call_status();
				offset += zephir_get_numberval(len);
				break;
			}
			if (type == 5) {
				ZEPHIR_INIT_NVAR(r);
				array_init(r);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 2);
				ZEPHIR_CALL_FUNCTION(&_13, "substr", &_10, value, &_5, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&_6, "readlshort", &_8, _13);
				zephir_check_call_status();
				zephir_array_append(&r, _6, PH_SEPARATE);
				offset += 2;
				_4 = ZEPHIR_STRING_OFFSET(value, offset);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, _4);
				ZEPHIR_CALL_FUNCTION(&_14, "ord", &_7, &_5);
				zephir_check_call_status();
				zephir_array_append(&r, _14, PH_SEPARATE);
				offset++;
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 2);
				ZEPHIR_CALL_FUNCTION(&_16, "substr", &_10, value, &_5, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&_15, "readlshort", &_8, _16);
				zephir_check_call_status();
				zephir_array_append(&r, _15, PH_SEPARATE);
				offset += 2;
				break;
			}
			if (type == 6) {
				ZEPHIR_INIT_NVAR(r);
				array_init(r);
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 4);
				ZEPHIR_CALL_FUNCTION(&_13, "substr", &_10, value, &_5, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&_6, "readlint", &_11, _13);
				zephir_check_call_status();
				zephir_array_append(&r, _6, PH_SEPARATE);
				offset += 4;
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 4);
				ZEPHIR_CALL_FUNCTION(&_15, "substr", &_10, value, &_5, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&_14, "readlint", &_11, _15);
				zephir_check_call_status();
				zephir_array_append(&r, _14, PH_SEPARATE);
				offset += 4;
				ZEPHIR_SINIT_NVAR(_5);
				ZVAL_LONG(&_5, offset);
				ZEPHIR_SINIT_NVAR(_9);
				ZVAL_LONG(&_9, 4);
				ZEPHIR_CALL_FUNCTION(&_17, "substr", &_10, value, &_5, &_9);
				zephir_check_call_status();
				ZEPHIR_CALL_SELF(&_16, "readlint", &_11, _17);
				zephir_check_call_status();
				zephir_array_append(&r, _16, PH_SEPARATE);
				offset += 4;
				break;
			}
		} while(0);

		if (types == 1) {
			ZEPHIR_INIT_NVAR(_18);
			array_init_size(_18, 3);
			zephir_array_fast_append(_18, r);
			ZEPHIR_INIT_NVAR(_19);
			ZVAL_LONG(_19, type);
			zephir_array_fast_append(_18, _19);
			zephir_array_update_long(&m, bottom, &_18, PH_COPY | PH_SEPARATE, "pocketmine/utils/Binary.zep", 113);
		} else {
			zephir_array_update_long(&m, bottom, &r, PH_COPY | PH_SEPARATE, "pocketmine/utils/Binary.zep", 115);
		}
		_4 = ZEPHIR_STRING_OFFSET(value, offset);
		b = _4;
		offset++;
	}
	RETURN_CTOR(m);

}

PHP_METHOD(PocketMine_Utils_Binary, readBool) {

	char _1;
	zval *b_param = NULL, *_0;
	zval *b = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &b_param);

	zephir_get_strval(b, b_param);


	ZEPHIR_INIT_VAR(_0);
	_1 = ZEPHIR_STRING_OFFSET(b, 0);
	if (_1 == 0) {
		ZVAL_BOOL(_0, 0);
	} else {
		ZVAL_BOOL(_0, 1);
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(PocketMine_Utils_Binary, writeBool) {

	zval *b_param = NULL;
	zend_bool b;

	zephir_fetch_params(0, 1, 0, &b_param);

	b = zephir_get_boolval(b_param);


	if (b == 1) {
		RETURN_STRING("\x01", 1);
	} else {
		RETURN_STRING("\x00", 1);
	}

}

PHP_METHOD(PocketMine_Utils_Binary, readByte) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	char _0;
	int b, ZEPHIR_LAST_CALL_STATUS;
	zend_bool isSigned, _4;
	zval *c_param = NULL, *isSigned_param = NULL, _1, *_2 = NULL;
	zval *c = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &c_param, &isSigned_param);

	zephir_get_strval(c, c_param);
	if (!isSigned_param) {
		isSigned = 1;
	} else {
		isSigned = zephir_get_boolval(isSigned_param);
	}


	_0 = ZEPHIR_STRING_OFFSET(c, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, _0);
	ZEPHIR_CALL_FUNCTION(&_2, "ord", &_3, &_1);
	zephir_check_call_status();
	b = (zephir_get_numberval(_2) * 1);
	_4 = isSigned == 1;
	if (_4) {
		_4 = ((b & 0x80)) > 0;
	}
	if (_4) {
		b = (-0x80 + ((b & 0x7f)));
	}
	RETURN_MM_LONG(b);

}

PHP_METHOD(PocketMine_Utils_Binary, writeByte) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zend_bool _0;
	zval *c_param = NULL, _1;
	int c, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &c_param);

	c = zephir_get_intval(c_param);


	_0 = c < 0;
	if (_0) {
		_0 = c >= -0x80;
	}
	if (_0) {
		c = ((0xff + c) + 1);
	}
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, c);
	ZEPHIR_RETURN_CALL_FUNCTION("chr", &_2, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Utils_Binary, readShort) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int unpacked, ZEPHIR_LAST_CALL_STATUS;
	zend_bool isSigned, _4;
	zval *str_param = NULL, *isSigned_param = NULL, _0, *_1 = NULL, *_3;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &isSigned_param);

	zephir_get_strval(str, str_param);
	if (!isSigned_param) {
		isSigned = 1;
	} else {
		isSigned = zephir_get_boolval(isSigned_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "n", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "unpack", &_2, &_0, str);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_long(&_3, _1, 1, PH_NOISY TSRMLS_CC);
	unpacked = zephir_get_intval(_3);
	_4 = unpacked > 0x7fff;
	if (_4) {
		_4 = isSigned == 1;
	}
	if (_4) {
		unpacked -= 0x10000;
	}
	RETURN_MM_LONG(unpacked);

}

PHP_METHOD(PocketMine_Utils_Binary, writeShort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *value_param = NULL, _0, _1;
	long value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_intval(value_param);


	if (value < 0) {
		value += 0x10000;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "n", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("pack", &_2, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Utils_Binary, readLShort) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int unpacked, ZEPHIR_LAST_CALL_STATUS;
	zend_bool isSigned, _4;
	zval *str_param = NULL, *isSigned_param = NULL, _0, *_1 = NULL, *_3;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &str_param, &isSigned_param);

	zephir_get_strval(str, str_param);
	if (!isSigned_param) {
		isSigned = 1;
	} else {
		isSigned = zephir_get_boolval(isSigned_param);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "v", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "unpack", &_2, &_0, str);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_long(&_3, _1, 1, PH_NOISY TSRMLS_CC);
	unpacked = zephir_get_intval(_3);
	_4 = unpacked > 0x7fff;
	if (_4) {
		_4 = isSigned == 1;
	}
	if (_4) {
		unpacked -= 0x10000;
	}
	RETURN_MM_LONG(unpacked);

}

PHP_METHOD(PocketMine_Utils_Binary, writeLShort) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *value_param = NULL, _0, _1;
	long value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_intval(value_param);


	if (value < 0) {
		value += 0x10000;
	}
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "v", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("pack", &_2, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Utils_Binary, readInt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	long unpacked;
	zval *str_param = NULL, _0, *_1 = NULL, *_3;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "N", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "unpack", &_2, &_0, str);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_long(&_3, _1, 1, PH_NOISY TSRMLS_CC);
	unpacked = zephir_get_intval(_3);
	if (unpacked > 2147483647) {
		unpacked -= 4294967296;
	}
	RETURN_MM_LONG(unpacked);

}

PHP_METHOD(PocketMine_Utils_Binary, writeInt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *value_param = NULL, _0, _1;
	long value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_intval(value_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "N", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("pack", &_2, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Utils_Binary, readLInt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	long unpacked;
	zval *str_param = NULL, _0, *_1 = NULL, *_3;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "V", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "unpack", &_2, &_0, str);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_3);
	zephir_array_fetch_long(&_3, _1, 1, PH_NOISY TSRMLS_CC);
	unpacked = zephir_get_intval(_3);
	if (unpacked > 2147483647) {
		unpacked -= 4294967296;
	}
	RETURN_MM_LONG(unpacked);

}

PHP_METHOD(PocketMine_Utils_Binary, writeLInt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *value_param = NULL, _0, _1;
	long value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_intval(value_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "V", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, value);
	ZEPHIR_RETURN_CALL_FUNCTION("pack", &_2, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Utils_Binary, readFloat) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zval *str_param = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4, *_5 = NULL, *_7 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "ENDIANNESS");
	if (unlikely(ZEPHIR_IS_LONG(_0, 0x00))) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "f", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "unpack", &_3, &_1, str);
		zephir_check_call_status();
		zephir_array_fetch_long(&_4, _2, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_4);
	} else {
		ZEPHIR_CALL_FUNCTION(&_5, "strrev", &_6, str);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "f", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "unpack", &_3, &_1, _5);
		zephir_check_call_status();
		zephir_array_fetch_long(&_4, _7, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Utils_Binary, writeFloat) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *value_param = NULL, *_0, _1 = zval_used_for_init, _2 = zval_used_for_init, *_4 = NULL;
	double value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_doubleval(value_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "ENDIANNESS");
	if (unlikely(ZEPHIR_IS_LONG(_0, 0x00))) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "f", 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_DOUBLE(&_2, value);
		ZEPHIR_RETURN_CALL_FUNCTION("pack", &_3, &_1, &_2);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "f", 0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_DOUBLE(&_2, value);
		ZEPHIR_CALL_FUNCTION(&_4, "pack", &_3, &_1, &_2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_4, "rev", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Utils_Binary, readLFloat) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zval *str_param = NULL, *_0, *_1 = NULL, *_2 = NULL, _4 = zval_used_for_init, *_5 = NULL, *_7;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "ENDIANNESS");
	if (unlikely(ZEPHIR_IS_LONG(_0, 0x00))) {
		ZEPHIR_CALL_FUNCTION(&_2, "strrev", &_3, str);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "f", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "unpack", &_6, &_4, _2);
		zephir_check_call_status();
		zephir_array_fetch_long(&_7, _5, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_7);
	} else {
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "f", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "unpack", &_6, &_4, str);
		zephir_check_call_status();
		zephir_array_fetch_long(&_7, _1, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_7);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Utils_Binary, writeLFloat) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *value_param = NULL, *_0, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL;
	double value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_doubleval(value_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "ENDIANNESS");
	if (unlikely(ZEPHIR_IS_LONG(_0, 0x00))) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "f", 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_DOUBLE(&_2, value);
		ZEPHIR_CALL_FUNCTION(&_3, "pack", &_4, &_1, &_2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_3, "rev", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "f", 0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_DOUBLE(&_2, value);
		ZEPHIR_RETURN_CALL_FUNCTION("pack", &_4, &_1, &_2);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Utils_Binary, printFloat) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zval *value_param = NULL, _0 = zval_used_for_init, _1 = zval_used_for_init, *_2 = NULL;
	double value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_doubleval(value_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "%F", 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_DOUBLE(&_1, value);
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", &_3, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "/(\\.\\d+?)0+$/", 0);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "$1", 0);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_replace", &_4, &_0, &_1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Utils_Binary, readDouble) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zval *str_param = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_4, *_5 = NULL, *_7 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "ENDIANNESS");
	if (unlikely(ZEPHIR_IS_LONG(_0, 0x00))) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "d", 0);
		ZEPHIR_CALL_FUNCTION(&_2, "unpack", &_3, &_1, str);
		zephir_check_call_status();
		zephir_array_fetch_long(&_4, _2, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_4);
	} else {
		ZEPHIR_CALL_FUNCTION(&_5, "strrev", &_6, str);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "d", 0);
		ZEPHIR_CALL_FUNCTION(&_7, "unpack", &_3, &_1, _5);
		zephir_check_call_status();
		zephir_array_fetch_long(&_4, _7, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Utils_Binary, writeDouble) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *value_param = NULL, *_0, _1 = zval_used_for_init, _2 = zval_used_for_init, *_4 = NULL;
	double value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_doubleval(value_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "ENDIANNESS");
	if (unlikely(ZEPHIR_IS_LONG(_0, 0x00))) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "d", 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_DOUBLE(&_2, value);
		ZEPHIR_RETURN_CALL_FUNCTION("pack", &_3, &_1, &_2);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "d", 0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_DOUBLE(&_2, value);
		ZEPHIR_CALL_FUNCTION(&_4, "pack", &_3, &_1, &_2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_4, "rev", NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Utils_Binary, readLDouble) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	zval *str_param = NULL, *_0, *_1 = NULL, *_2 = NULL, _4 = zval_used_for_init, *_5 = NULL, *_7;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "ENDIANNESS");
	if (unlikely(ZEPHIR_IS_LONG(_0, 0x00))) {
		ZEPHIR_CALL_FUNCTION(&_2, "strrev", &_3, str);
		zephir_check_call_status();
		ZEPHIR_SINIT_VAR(_4);
		ZVAL_STRING(&_4, "d", 0);
		ZEPHIR_CALL_FUNCTION(&_5, "unpack", &_6, &_4, _2);
		zephir_check_call_status();
		zephir_array_fetch_long(&_7, _5, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_7);
	} else {
		ZEPHIR_SINIT_NVAR(_4);
		ZVAL_STRING(&_4, "d", 0);
		ZEPHIR_CALL_FUNCTION(&_1, "unpack", &_6, &_4, str);
		zephir_check_call_status();
		zephir_array_fetch_long(&_7, _1, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		RETURN_CTOR(_7);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Utils_Binary, writeLDouble) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	zval *value_param = NULL, *_0, _1 = zval_used_for_init, _2 = zval_used_for_init, *_3 = NULL;
	double value;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	value = zephir_get_doubleval(value_param);


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "ENDIANNESS");
	if (unlikely(ZEPHIR_IS_LONG(_0, 0x00))) {
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_STRING(&_1, "d", 0);
		ZEPHIR_SINIT_VAR(_2);
		ZVAL_DOUBLE(&_2, value);
		ZEPHIR_CALL_FUNCTION(&_3, "pack", &_4, &_1, &_2);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(_3, "rev", NULL);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_STRING(&_1, "d", 0);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_DOUBLE(&_2, value);
		ZEPHIR_RETURN_CALL_FUNCTION("pack", &_4, &_1, &_2);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Utils_Binary, __s_not) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	char _1;
	int i = 0, ZEPHIR_LAST_CALL_STATUS;
	zval *s_param = NULL, *_0 = NULL, _2 = zval_used_for_init, *_3 = NULL, *_5 = NULL;
	zval *s = NULL, *r;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &s_param);

	zephir_get_strval(s, s_param);
	ZEPHIR_INIT_VAR(r);
	ZVAL_STRING(r, "", 1);


	while (1) {
		if (!(i < zephir_fast_strlen_ev(s))) {
			break;
		}
		_1 = ZEPHIR_STRING_OFFSET(s, i);
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, _1);
		ZEPHIR_CALL_FUNCTION(&_3, "ord", &_4, &_2);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_2);
		ZVAL_LONG(&_2, (-1 - zephir_get_numberval(_3)));
		ZEPHIR_CALL_FUNCTION(&_5, "chr", &_6, &_2);
		zephir_check_call_status();
		zephir_concat_self(&r, _5 TSRMLS_CC);
	}
	RETURN_CTOR(r);

}

PHP_METHOD(PocketMine_Utils_Binary, readLong) {

	zephir_fcall_cache_entry *_8 = NULL, *_15 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL;
	int i = 0, ZEPHIR_LAST_CALL_STATUS;
	zend_bool isSigned, negative = 0;
	zval *x = NULL, *isSigned_param = NULL, *value = NULL, *_0 = NULL, *_1, *_2 = NULL, *_4 = NULL, _6 = zval_used_for_init, _7 = zval_used_for_init, *_9, *_10, *_11 = NULL, *_12, *_13 = NULL, *_14 = NULL, *_16 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &x, &isSigned_param);

	ZEPHIR_SEPARATE_PARAM(x);
	if (!isSigned_param) {
		isSigned = 1;
	} else {
		isSigned = zephir_get_boolval(isSigned_param);
	}
	ZEPHIR_INIT_VAR(value);
	ZVAL_STRING(value, "0", 1);


	if (isSigned == 1) {
		ZEPHIR_INIT_VAR(_0);
		zephir_array_fetch_long(&_1, x, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_2, "ord", &_3, _1);
		zephir_check_call_status();
		if (((int) (zephir_get_numberval(_2)) & 0x80) > 0) {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_BOOL(_0, 1);
		} else {
			ZEPHIR_INIT_NVAR(_0);
			ZVAL_BOOL(_0, 0);
		}
		negative = zephir_is_true(_0);
		if (negative == 1) {
			ZEPHIR_CALL_SELF(&_4, "__s_not", &_5, x);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(x, _4);
		}
	}
	while (1) {
		if (!(i < 8)) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, 4294967296);
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 0);
		ZEPHIR_CALL_FUNCTION(&_2, "bcmul", &_8, value, &_6, &_7);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _2);
		zephir_array_fetch_long(&_1, x, i, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_2, "ord", &_3, _1);
		zephir_check_call_status();
		zephir_array_fetch_long(&_9, x, (i + 1), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_4, "ord", &_3, _9);
		zephir_check_call_status();
		zephir_array_fetch_long(&_10, x, (i + 2), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_11, "ord", &_3, _10);
		zephir_check_call_status();
		zephir_array_fetch_long(&_12, x, (i + 3), PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_13, "ord", &_3, _12);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_6);
		ZVAL_LONG(&_6, ((((0x1000000 * zephir_get_numberval(_2)) + (zephir_get_numberval(_4) * 65536)) + (zephir_get_numberval(_11) * 256)) + zephir_get_numberval(_13)));
		ZEPHIR_SINIT_NVAR(_7);
		ZVAL_LONG(&_7, 0);
		ZEPHIR_CALL_FUNCTION(&_14, "bcadd", &_15, value, &_6, &_7);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _14);
		i += 4;
	}
	ZEPHIR_INIT_VAR(_16);
	if (negative == 1) {
		ZEPHIR_CONCAT_SV(_16, "-", value);
	} else {
		ZEPHIR_CPY_WRT(_16, value);
	}
	RETURN_CCTOR(_16);

}

PHP_METHOD(PocketMine_Utils_Binary, writeLong) {

	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_15 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_10 = NULL, *_17 = NULL, *_18 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool negative = 0;
	long temp;
	zval *value = NULL, *x = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_3, _5 = zval_used_for_init, *_7 = NULL, *_9 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, _16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);

	ZEPHIR_SEPARATE_PARAM(value);
	ZEPHIR_INIT_VAR(x);
	ZVAL_STRING(x, "", 1);


	zephir_array_fetch_long(&_0, value, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	if (ZEPHIR_IS_STRING(_0, "-")) {
		negative = 1;
		ZEPHIR_SINIT_VAR(_1);
		ZVAL_LONG(&_1, 1);
		ZEPHIR_CALL_FUNCTION(&_2, "bcadd", NULL, value, &_1);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _2);
		zephir_array_fetch_long(&_3, value, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_3, "-")) {
			ZEPHIR_SINIT_NVAR(_1);
			ZVAL_LONG(&_1, 1);
			ZEPHIR_CALL_FUNCTION(&_2, "substr", &_4, value, &_1);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, _2);
		}
	}
	while (1) {
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 0);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 0);
		ZEPHIR_CALL_FUNCTION(&_2, "bccomp", &_6, value, &_1, &_5);
		zephir_check_call_status();
		if (!(ZEPHIR_GT_LONG(_2, 0))) {
			break;
		}
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 16777216);
		ZEPHIR_CALL_FUNCTION(&_7, "bcmod", &_8, value, &_1);
		zephir_check_call_status();
		temp = zephir_get_intval(_7);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, (((temp & 0xFF0000)) / 65536));
		ZEPHIR_CALL_FUNCTION(&_9, "chr", &_10, &_1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, (((temp & 0xFF00)) / 256));
		ZEPHIR_CALL_FUNCTION(&_11, "chr", &_10, &_1);
		zephir_check_call_status();
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, (temp & 0xFF));
		ZEPHIR_CALL_FUNCTION(&_12, "chr", &_10, &_1);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_13);
		ZEPHIR_CONCAT_VVVV(_13, _9, _11, _12, x);
		ZEPHIR_CPY_WRT(x, _13);
		ZEPHIR_SINIT_NVAR(_1);
		ZVAL_LONG(&_1, 16777216);
		ZEPHIR_SINIT_NVAR(_5);
		ZVAL_LONG(&_5, 0);
		ZEPHIR_CALL_FUNCTION(&_14, "bcdiv", &_15, value, &_1, &_5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, _14);
	}
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_LONG(&_5, 8);
	ZEPHIR_CALL_FUNCTION(&_2, "substr", &_4, x, &_1, &_5);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 8);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_STRING(&_5, "\x00", 0);
	ZEPHIR_SINIT_VAR(_16);
	ZVAL_LONG(&_16, 0);
	ZEPHIR_CALL_FUNCTION(&x, "str_pad", &_17, _2, &_1, &_5, &_16);
	zephir_check_call_status();
	if (negative == 1) {
		ZEPHIR_CALL_SELF(&_7, "__s_not", &_18, x);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(x, _7);
	}
	RETURN_CCTOR(x);

}

PHP_METHOD(PocketMine_Utils_Binary, readLLong) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *str_param = NULL, *_0 = NULL, *_1 = NULL;
	zval *str = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &str_param);

	zephir_get_strval(str, str_param);


	ZEPHIR_CALL_FUNCTION(&_1, "strrev", &_2, str);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_SELF("readlong", NULL, _1);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Utils_Binary, writeLLong) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *_0 = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	zephir_get_strval(value, value_param);


	ZEPHIR_CALL_SELF(&_0, "writelong", NULL, value);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_0, "rev", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

