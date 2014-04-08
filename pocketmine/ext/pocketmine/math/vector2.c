
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/*
 *
 *  ____            _        _   __  __ _                  __  __ ____  
 * |  _ \ ___   ___| | _____| |_|  \/  (_)_ __   ___      |  \/  |  _ \ 
 * | |_) / _ \ / __| |/ / _ \ __| |\/| | | '_ \ / _ \_____| |\/| | |_) |
 * |  __/ (_) | (__|   <  __/ |_| |  | | | | | |  __/_____| |  | |  __/ 
 * |_|   \___/ \___|_|\_\___|\__|_|  |_|_|_| |_|\___|     |_|  |_|_| 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * @author PocketMine Team
 * @link http://www.pocketmine.net/
 * 
 *
*/
ZEPHIR_INIT_CLASS(PocketMine_Math_Vector2) {

	ZEPHIR_REGISTER_CLASS(PocketMine\\Math, Vector2, pocketmine, math_vector2, pocketmine_math_vector2_method_entry, 0);

	zend_declare_property_null(pocketmine_math_vector2_ce, SL("x"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(pocketmine_math_vector2_ce, SL("y"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PocketMine_Math_Vector2, __construct) {

	zval *x = NULL, *y = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &x, &y);

	if (!x) {
		ZEPHIR_INIT_VAR(x);
		ZVAL_LONG(x, 0);
	}
	if (!y) {
		ZEPHIR_INIT_VAR(y);
		ZVAL_LONG(y, 0);
	}


	zephir_update_property_this(this_ptr, SL("x"), x TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("y"), y TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Math_Vector2, getX) {


	RETURN_MEMBER(this_ptr, "x");

}

PHP_METHOD(PocketMine_Math_Vector2, getY) {


	RETURN_MEMBER(this_ptr, "y");

}

PHP_METHOD(PocketMine_Math_Vector2, getFloorX) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("x"), PH_NOISY_CC);
	RETURN_MM_LONG(zephir_get_intval(_0));

}

PHP_METHOD(PocketMine_Math_Vector2, getFloorY) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("y"), PH_NOISY_CC);
	RETURN_MM_LONG(zephir_get_intval(_0));

}

PHP_METHOD(PocketMine_Math_Vector2, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *x, *y = NULL, *_0 = NULL, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &x, &y);

	if (!y) {
		ZEPHIR_INIT_VAR(y);
		ZVAL_LONG(y, 0);
	}


	if (zephir_instance_of_ev(x, pocketmine_math_vector2_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property(&_1, x, SL("x"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, x, SL("y"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, _1, _2);
		zephir_check_call_status();
		RETURN_CCTOR(_0);
	}
	object_init_ex(return_value, pocketmine_math_vector2_ce);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_add_function(_4, _3, x TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_add_function(_5, _3, y TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _4, _5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector2, subtract) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *x, *y = NULL, *_0 = NULL, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &x, &y);

	if (!y) {
		ZEPHIR_INIT_VAR(y);
		ZVAL_LONG(y, 0);
	}


	if (zephir_instance_of_ev(x, pocketmine_math_vector2_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property(&_1, x, SL("x"), PH_NOISY_CC);
		zephir_negate(_1 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, x, SL("y"), PH_NOISY_CC);
		zephir_negate(_2 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, _1, _2);
		zephir_check_call_status();
		RETURN_CCTOR(_0);
	}
	zephir_negate(x TSRMLS_CC);
	zephir_negate(y TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, x, y);
	zephir_check_call_status();
	RETURN_CCTOR(_0);

}

PHP_METHOD(PocketMine_Math_Vector2, ceil) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, pocketmine_math_vector2_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, ((zephir_get_numberval(_0) + 1)));
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, ((zephir_get_numberval(_1) + 1)));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector2, floor) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, pocketmine_math_vector2_ce);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, zephir_get_intval(_0));
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, zephir_get_intval(_1));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector2, round) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL, *_3, *_4 = NULL, *_5, *_6;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, pocketmine_math_vector2_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "round", &_2, _0);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "round", &_2, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, zephir_get_intval(_1));
	ZEPHIR_INIT_VAR(_6);
	ZVAL_LONG(_6, zephir_get_intval(_4));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _5, _6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector2, abs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL, *_3, *_4 = NULL;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, pocketmine_math_vector2_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", &_2, _0);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "abs", &_2, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1, _4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector2, multiply) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	object_init_ex(return_value, pocketmine_math_vector2_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	mul_function(_1, _0, number TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	mul_function(_2, _0, number TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector2, divide) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_1, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	object_init_ex(return_value, pocketmine_math_vector2_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	div_function(_1, _0, number TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	div_function(_2, _0, number TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1, _2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector2, distance) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *x, *y = NULL, *_0 = NULL, *_1, *_2, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &x, &y);

	if (!y) {
		ZEPHIR_INIT_VAR(y);
		ZVAL_LONG(y, 0);
	}


	if (zephir_instance_of_ev(x, pocketmine_math_vector2_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property(&_1, x, SL("x"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, x, SL("y"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "distancesquared", NULL, _1, _2);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3, "sqrt", &_4, _0);
		zephir_check_call_status();
		RETURN_MM_DOUBLE(zephir_get_doubleval(_3));
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "distancesquared", NULL, x, y);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "sqrt", &_4, _0);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_get_doubleval(_3));

}

PHP_METHOD(PocketMine_Math_Vector2, distanceSquared) {

	zephir_nts_static zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *x, *y = NULL, *_0 = NULL, *_1, *_2, *_3, _4, _5 = zval_used_for_init, _7, *_8 = NULL, *_9;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &x, &y);

	if (!y) {
		ZEPHIR_INIT_VAR(y);
		ZVAL_LONG(y, 0);
	}


	if (zephir_instance_of_ev(x, pocketmine_math_vector2_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property(&_1, x, SL("x"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, x, SL("y"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "distancesquared", NULL, _1, _2);
		zephir_check_call_status();
		RETURN_MM_DOUBLE(zephir_get_doubleval(_0));
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_4);
	sub_function(&_4, _3, x TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 2);
	ZEPHIR_CALL_FUNCTION(&_0, "pow", &_6, _4, &_5);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_5);
	sub_function(&_5, _3, y TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 2);
	ZEPHIR_CALL_FUNCTION(&_8, "pow", &_6, _5, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	zephir_add_function(_9, _0, _8 TSRMLS_CC);
	RETURN_MM_DOUBLE(zephir_get_doubleval(_9));

}

PHP_METHOD(PocketMine_Math_Vector2, length) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "lengthsquared",  NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "sqrt", &_2, _0);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_get_doubleval(_1));

}

PHP_METHOD(PocketMine_Math_Vector2, lengthSquared) {

	zval *_0, *_1, _2, _3, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	mul_function(&_2, _0, _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	mul_function(&_3, _0, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_add_function(_4, &_2, &_3 TSRMLS_CC);
	RETURN_MM_DOUBLE(zephir_get_doubleval(_4));

}

PHP_METHOD(PocketMine_Math_Vector2, normalize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3;
	double len;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "length",  NULL);
	zephir_check_call_status();
	len = zephir_get_doubleval(_0);
	if (len != 0) {
		ZEPHIR_INIT_VAR(_2);
		ZVAL_DOUBLE(_2, len);
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "divide", NULL, _2);
		zephir_check_call_status();
		RETURN_CCTOR(_1);
	}
	object_init_ex(return_value, pocketmine_math_vector2_ce);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector2, dot) {

	zval *v, *_0, *_1, _2, _3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v);



	if (!(zephir_instance_of_ev(v, pocketmine_math_vector2_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'v' must be an instance of 'PocketMine\\Math\\Vector2'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(v, SL("x"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	mul_function(&_2, _0, _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(v, SL("y"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	mul_function(&_3, _0, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_add_function(_4, &_2, &_3 TSRMLS_CC);
	RETURN_MM_DOUBLE(zephir_get_doubleval(_4));

}

PHP_METHOD(PocketMine_Math_Vector2, __toString) {

	zval *_1 = NULL, *_3 = NULL;
	zval *_0, *_2;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("x"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("y"), PH_NOISY_CC);
	zephir_get_strval(_3, _2);
	ZEPHIR_CONCAT_SVSVS(return_value, "Vector2(x=", _1, ",y=", _3, ")");
	RETURN_MM();

}

