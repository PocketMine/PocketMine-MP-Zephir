
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

ZEPHIR_INIT_CLASS(PocketMine_Level_Generator_Noise_Generator) {

	ZEPHIR_REGISTER_CLASS(PocketMine\\Level\\Generator\\Noise, Generator, pocketmine, level_generator_noise_generator, pocketmine_level_generator_noise_generator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(pocketmine_level_generator_noise_generator_ce, SL("perm"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(pocketmine_level_generator_noise_generator_ce, SL("offsetX"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(pocketmine_level_generator_noise_generator_ce, SL("offsetY"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(pocketmine_level_generator_noise_generator_ce, SL("offsetZ"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(pocketmine_level_generator_noise_generator_ce, SL("octaves"), 8, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(pocketmine_level_generator_noise_generator_ce, SL("frequency"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(pocketmine_level_generator_noise_generator_ce, SL("amplitude"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, floor) {

	zval *x_param = NULL, *_0;
	double x;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &x_param);

	x = zephir_get_doubleval(x_param);


	ZEPHIR_INIT_VAR(_0);
	if (x >= 0) {
		ZVAL_LONG(_0, (long) (x));
	} else {
		ZVAL_LONG(_0, ((long) (x) - 1));
	}
	RETURN_CCTOR(_0);

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, fade) {

	zval *x_param = NULL;
	double x;

	zephir_fetch_params(0, 1, 0, &x_param);

	x = zephir_get_doubleval(x_param);


	RETURN_DOUBLE(((double) ((x * x) * x) * (((x * (((x * (double) 6) - (double) (15)))) + (double) (10)))));

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, lerp) {

	zval *x_param = NULL, *y_param = NULL, *z_param = NULL;
	double x, y, z;

	zephir_fetch_params(0, 3, 0, &x_param, &y_param, &z_param);

	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);


	RETURN_DOUBLE((y + (x * ((z - y)))));

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, grad) {

	zend_bool _2;
	double x, y, z, u, v;
	zval *hash_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, *_0, *_1, *_3, *_4;
	int hash;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 0, &hash_param, &x_param, &y_param, &z_param);

	hash = zephir_get_intval(hash_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);


	hash = (hash & 15);
	ZEPHIR_INIT_VAR(_0);
	if (hash < 8) {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_DOUBLE(_0, x);
	} else {
		ZEPHIR_INIT_BNVAR(_0);
		ZVAL_DOUBLE(_0, y);
	}
	u = zephir_get_numberval(_0);
	ZEPHIR_INIT_VAR(_1);
	if (hash < 4) {
		ZEPHIR_INIT_BNVAR(_1);
		ZVAL_DOUBLE(_1, y);
	} else {
		_2 = hash == 12;
		if (!(_2)) {
			_2 = hash == 14;
		}
		if (_2) {
			ZEPHIR_INIT_BNVAR(_1);
			ZVAL_DOUBLE(_1, x);
		} else {
			ZEPHIR_INIT_BNVAR(_1);
			ZVAL_DOUBLE(_1, z);
		}
	}
	v = zephir_get_numberval(_1);
	ZEPHIR_INIT_VAR(_3);
	if (((hash & 1)) == 0) {
		ZEPHIR_INIT_BNVAR(_3);
		ZVAL_DOUBLE(_3, u);
	} else {
		ZEPHIR_INIT_BNVAR(_3);
		ZVAL_DOUBLE(_3, -u);
	}
	ZEPHIR_INIT_VAR(_4);
	if (((hash & 2)) == 0) {
		ZEPHIR_INIT_BNVAR(_4);
		ZVAL_DOUBLE(_4, v);
	} else {
		ZEPHIR_INIT_BNVAR(_4);
		ZVAL_DOUBLE(_4, -v);
	}
	zephir_add_function(return_value, _3, _4 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, getNoise2D) {

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, getNoise3D) {

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, noise2D) {

	zephir_fcall_cache_entry *_4 = NULL;
	int i = 0, ZEPHIR_LAST_CALL_STATUS;
	zend_bool normalized;
	zval *x_param = NULL, *z_param = NULL, *normalized_param = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_5, *_6;
	double x, z, result = 0, amp = 1, freq = 1, max = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &x_param, &z_param, &normalized_param);

	x = zephir_get_doubleval(x_param);
	z = zephir_get_doubleval(z_param);
	if (!normalized_param) {
		normalized = 0;
	} else {
		normalized = zephir_get_boolval(normalized_param);
	}


	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("octaves"), PH_NOISY_CC);
		if (!(ZEPHIR_GT_LONG(_0, i))) {
			break;
		}
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_DOUBLE(_2, (x * freq));
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_DOUBLE(_3, (z * freq));
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getnoise2d", &_4, _2, _3);
		zephir_check_call_status();
		result += (double) (zephir_get_doubleval(_1) * amp);
		max += amp;
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("frequency"), PH_NOISY_CC);
		freq *= zephir_get_numberval(_5);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("amplitude"), PH_NOISY_CC);
		amp *= zephir_get_numberval(_6);
		i++;
	}
	if (normalized == 1) {
		result = (result / max);
	}
	RETURN_MM_DOUBLE(result);

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, noise3D) {

	zephir_fcall_cache_entry *_5 = NULL;
	int i = 0, ZEPHIR_LAST_CALL_STATUS;
	zend_bool normalized;
	zval *x_param = NULL, *y_param = NULL, *z_param = NULL, *normalized_param = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_6, *_7;
	double x, y, z, result = 0, amp = 1, freq = 1, max = 0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &x_param, &y_param, &z_param, &normalized_param);

	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);
	if (!normalized_param) {
		normalized = 0;
	} else {
		normalized = zephir_get_boolval(normalized_param);
	}


	while (1) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("octaves"), PH_NOISY_CC);
		if (!(ZEPHIR_GT_LONG(_0, i))) {
			break;
		}
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_DOUBLE(_2, (x * freq));
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_DOUBLE(_3, (y * freq));
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_DOUBLE(_4, (z * freq));
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getnoise3d", &_5, _2, _3, _4);
		zephir_check_call_status();
		result += (double) (zephir_get_doubleval(_1) * amp);
		max += amp;
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("frequency"), PH_NOISY_CC);
		freq *= zephir_get_numberval(_6);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("amplitude"), PH_NOISY_CC);
		amp *= zephir_get_numberval(_7);
		i++;
	}
	if (normalized == 1) {
		result = (result / max);
	}
	RETURN_MM_DOUBLE(result);

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, setOffset) {

	zval *x_param = NULL, *y_param = NULL, *z_param = NULL, *_0;
	double x, y, z;

	zephir_fetch_params(0, 3, 0, &x_param, &y_param, &z_param);

	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, x);
	zephir_update_property_this(this_ptr, SL("offsetX"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, y);
	zephir_update_property_this(this_ptr, SL("offsetY"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, z);
	zephir_update_property_this(this_ptr, SL("offsetZ"), _0 TSRMLS_CC);

}

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, __construct) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("perm"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

