
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
ZEPHIR_INIT_CLASS(PocketMine_Math_Vector3) {

	ZEPHIR_REGISTER_CLASS(PocketMine\\Math, Vector3, pocketmine, math_vector3, pocketmine_math_vector3_method_entry, 0);

	zend_declare_property_null(pocketmine_math_vector3_ce, SL("x"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(pocketmine_math_vector3_ce, SL("y"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(pocketmine_math_vector3_ce, SL("z"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PocketMine_Math_Vector3, __construct) {

	zval *x = NULL, *y = NULL, *z = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &x, &y, &z);

	if (!x) {
		ZEPHIR_INIT_VAR(x);
		ZVAL_LONG(x, 0);
	}
	if (!y) {
		ZEPHIR_INIT_VAR(y);
		ZVAL_LONG(y, 0);
	}
	if (!z) {
		ZEPHIR_INIT_VAR(z);
		ZVAL_LONG(z, 0);
	}


	zephir_update_property_this(this_ptr, SL("x"), x TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("y"), y TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("z"), z TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PocketMine_Math_Vector3, getX) {


	RETURN_MEMBER(this_ptr, "x");

}

PHP_METHOD(PocketMine_Math_Vector3, getY) {


	RETURN_MEMBER(this_ptr, "y");

}

PHP_METHOD(PocketMine_Math_Vector3, getZ) {


	RETURN_MEMBER(this_ptr, "z");

}

PHP_METHOD(PocketMine_Math_Vector3, getFloorX) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("x"), PH_NOISY_CC);
	RETURN_MM_LONG(zephir_get_intval(_0));

}

PHP_METHOD(PocketMine_Math_Vector3, getFloorY) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("y"), PH_NOISY_CC);
	RETURN_MM_LONG(zephir_get_intval(_0));

}

PHP_METHOD(PocketMine_Math_Vector3, getFloorZ) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("z"), PH_NOISY_CC);
	RETURN_MM_LONG(zephir_get_intval(_0));

}

PHP_METHOD(PocketMine_Math_Vector3, getRight) {


	RETURN_MEMBER(this_ptr, "x");

}

PHP_METHOD(PocketMine_Math_Vector3, getUp) {


	RETURN_MEMBER(this_ptr, "y");

}

PHP_METHOD(PocketMine_Math_Vector3, getForward) {


	RETURN_MEMBER(this_ptr, "z");

}

PHP_METHOD(PocketMine_Math_Vector3, getSouth) {


	RETURN_MEMBER(this_ptr, "x");

}

PHP_METHOD(PocketMine_Math_Vector3, getWest) {


	RETURN_MEMBER(this_ptr, "z");

}

PHP_METHOD(PocketMine_Math_Vector3, add) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *x, *y = NULL, *z = NULL, *_0 = NULL, *_1, *_2, *_3, *_4, *_5, *_6, *_7;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &x, &y, &z);

	if (!y) {
		ZEPHIR_INIT_VAR(y);
		ZVAL_LONG(y, 0);
	}
	if (!z) {
		ZEPHIR_INIT_VAR(z);
		ZVAL_LONG(z, 0);
	}


	if (zephir_instance_of_ev(x, pocketmine_math_vector3_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property(&_1, x, SL("x"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, x, SL("y"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, x, SL("z"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, _1, _2, _3);
		zephir_check_call_status();
		RETURN_CCTOR(_0);
	}
	object_init_ex(return_value, pocketmine_math_vector3_ce);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_add_function(_5, _4, x TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_add_function(_6, _4, y TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	zephir_add_function(_7, _4, z TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _5, _6, _7);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector3, subtract) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *x, *y = NULL, *z = NULL, *_0 = NULL, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &x, &y, &z);

	if (!y) {
		ZEPHIR_INIT_VAR(y);
		ZVAL_LONG(y, 0);
	}
	if (!z) {
		ZEPHIR_INIT_VAR(z);
		ZVAL_LONG(z, 0);
	}


	if (zephir_instance_of_ev(x, pocketmine_math_vector3_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property(&_1, x, SL("x"), PH_NOISY_CC);
		zephir_negate(_1 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, x, SL("y"), PH_NOISY_CC);
		zephir_negate(_2 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, x, SL("z"), PH_NOISY_CC);
		zephir_negate(_3 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, _1, _2, _3);
		zephir_check_call_status();
		RETURN_CCTOR(_0);
	}
	zephir_negate(x TSRMLS_CC);
	zephir_negate(y TSRMLS_CC);
	zephir_negate(z TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "add", NULL, x, y, z);
	zephir_check_call_status();
	RETURN_CCTOR(_0);

}

PHP_METHOD(PocketMine_Math_Vector3, ceil) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, pocketmine_math_vector3_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, ((zephir_get_numberval(_0) + 1)));
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, ((zephir_get_numberval(_1) + 1)));
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, ((zephir_get_numberval(_2) + 1)));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _3, _4, _5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector3, floor) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1, *_2, *_3, *_4, *_5;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, pocketmine_math_vector3_ce);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, zephir_get_intval(_0));
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, zephir_get_intval(_1));
	ZEPHIR_INIT_VAR(_5);
	ZVAL_LONG(_5, zephir_get_intval(_2));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _3, _4, _5);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector3, round) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL, *_3, *_4 = NULL, *_5, *_6 = NULL, *_7, *_8, *_9;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, pocketmine_math_vector3_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "round", &_2, _0);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "round", &_2, _3);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_6, "round", &_2, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_7);
	ZVAL_LONG(_7, zephir_get_intval(_1));
	ZEPHIR_INIT_VAR(_8);
	ZVAL_LONG(_8, zephir_get_intval(_4));
	ZEPHIR_INIT_VAR(_9);
	ZVAL_LONG(_9, zephir_get_intval(_6));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _7, _8, _9);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector3, abs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval *_0, *_1 = NULL, *_3, *_4 = NULL, *_5, *_6 = NULL;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, pocketmine_math_vector3_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "abs", &_2, _0);
	zephir_check_call_status();
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_4, "abs", &_2, _3);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_6, "abs", &_2, _5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1, _4, _6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector3, multiply) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	object_init_ex(return_value, pocketmine_math_vector3_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	mul_function(_1, _0, number TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	mul_function(_2, _0, number TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	mul_function(_3, _0, number TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector3, divide) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *number, *_0, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &number);



	object_init_ex(return_value, pocketmine_math_vector3_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	div_function(_1, _0, number TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	div_function(_2, _0, number TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	div_function(_3, _0, number TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _1, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector3, getSide) {

	zephir_fcall_cache_entry *_4 = NULL;
	zval *side_param = NULL, *step_param = NULL, *_0, *_1, *_2, *_3 = NULL;
	int side, step, ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &side_param, &step_param);

	side = zephir_get_intval(side_param);
	if (!step_param) {
		step = 1;
	} else {
		step = zephir_get_intval(step_param);
	}


	do {
		if (side == 0) {
			object_init_ex(return_value, pocketmine_math_vector3_ce);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_3);
			ZVAL_LONG(_3, (zephir_get_numberval(_1) - step));
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_4, _0, _3, _2);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (side == 1) {
			object_init_ex(return_value, pocketmine_math_vector3_ce);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_LONG(_3, (zephir_get_numberval(_1) + step));
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_4, _0, _3, _2);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (side == 2) {
			object_init_ex(return_value, pocketmine_math_vector3_ce);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_LONG(_3, (zephir_get_numberval(_2) - step));
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_4, _0, _1, _3);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (side == 3) {
			object_init_ex(return_value, pocketmine_math_vector3_ce);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_LONG(_3, (zephir_get_numberval(_2) + step));
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_4, _0, _1, _3);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (side == 4) {
			object_init_ex(return_value, pocketmine_math_vector3_ce);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_LONG(_3, (zephir_get_numberval(_0) - step));
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_4, _3, _1, _2);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (side == 5) {
			object_init_ex(return_value, pocketmine_math_vector3_ce);
			_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
			_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
			_2 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
			ZEPHIR_INIT_NVAR(_3);
			ZVAL_LONG(_3, (zephir_get_numberval(_0) + step));
			ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", &_4, _3, _1, _2);
			zephir_check_call_status();
			RETURN_MM();
		}
	} while(0);

	RETURN_THIS();

}

PHP_METHOD(PocketMine_Math_Vector3, distance) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *pos, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pos);



	if (!(zephir_instance_of_ev(pos, pocketmine_math_vector3_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'pos' must be an instance of 'PocketMine\\Math\\Vector3'", "", 0);
		return;
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "distancesquared", NULL, pos);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "sqrt", &_2, _0);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_get_doubleval(_1));

}

PHP_METHOD(PocketMine_Math_Vector3, distanceSquared) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL;
	zval *pos, *_0, *_1, _2 = zval_used_for_init, _3 = zval_used_for_init, *_4 = NULL, *_6, *_7, *_8 = NULL, *_9, *_10, _11, *_12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pos);



	if (!(zephir_instance_of_ev(pos, pocketmine_math_vector3_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'pos' must be an instance of 'PocketMine\\Math\\Vector3'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, pos, SL("x"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_DOUBLE(&_2, (zephir_get_doubleval(_0) - zephir_get_doubleval(_1)));
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_FUNCTION(&_4, "pow", &_5, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property_this(&_6, this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property_this(&_7, pos, SL("y"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_2);
	ZVAL_DOUBLE(&_2, (zephir_get_doubleval(_6) - zephir_get_doubleval(_7)));
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_FUNCTION(&_8, "pow", &_5, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_2);
	zephir_add_function(&_2, _4, _8 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_9);
	zephir_read_property_this(&_9, this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property_this(&_10, pos, SL("z"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_DOUBLE(&_3, (zephir_get_doubleval(_9) - zephir_get_doubleval(_10)));
	ZEPHIR_SINIT_VAR(_11);
	ZVAL_LONG(&_11, 2);
	ZEPHIR_CALL_FUNCTION(&_4, "pow", &_5, &_3, &_11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_12);
	zephir_add_function(_12, &_2, _4 TSRMLS_CC);
	RETURN_MM_DOUBLE(zephir_get_doubleval(_12));

}

PHP_METHOD(PocketMine_Math_Vector3, maxPlainDistance) {

	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *x, *z, *_0 = NULL, *_1 = NULL, *_2 = NULL, _3 = zval_used_for_init, *_5 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &x, &z);



	if (zephir_instance_of_ev(x, pocketmine_math_vector3_ce TSRMLS_CC)) {
		ZEPHIR_OBS_VAR(_1);
		zephir_read_property(&_1, x, SL("x"), PH_NOISY_CC);
		ZEPHIR_OBS_VAR(_2);
		zephir_read_property(&_2, x, SL("z"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "maxplaindistance", NULL, _1, _2);
		zephir_check_call_status();
		RETURN_MM_DOUBLE(zephir_get_doubleval(_0));
	} else {
		if (zephir_instance_of_ev(x, pocketmine_math_vector2_ce TSRMLS_CC)) {
			ZEPHIR_OBS_NVAR(_1);
			zephir_read_property(&_1, x, SL("x"), PH_NOISY_CC);
			ZEPHIR_OBS_NVAR(_2);
			zephir_read_property(&_2, x, SL("y"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_0, this_ptr, "maxplaindistance", NULL, _1, _2);
			zephir_check_call_status();
			RETURN_MM_DOUBLE(zephir_get_doubleval(_0));
		}
	}
	ZEPHIR_OBS_NVAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_DOUBLE(&_3, (zephir_get_doubleval(_1) - zephir_get_doubleval(x)));
	ZEPHIR_CALL_FUNCTION(&_0, "abs", &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_DOUBLE(&_3, (zephir_get_doubleval(_2) - zephir_get_doubleval(z)));
	ZEPHIR_CALL_FUNCTION(&_5, "abs", &_4, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "max", &_7, _0, _5);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_get_doubleval(_6));

}

PHP_METHOD(PocketMine_Math_Vector3, length) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, _1, *_2 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "lengthsquared",  NULL);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_DOUBLE(&_1, zephir_get_doubleval(_0));
	ZEPHIR_CALL_FUNCTION(&_2, "sqrt", &_3, &_1);
	zephir_check_call_status();
	RETURN_MM_DOUBLE(zephir_get_doubleval(_2));

}

PHP_METHOD(PocketMine_Math_Vector3, lengthSquared) {

	zval *_0, *_1, _2 = zval_used_for_init, _3, _4, *_5;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	mul_function(&_2, _0, _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	mul_function(&_3, _0, _1 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	zephir_add_function(&_4, &_2, &_3 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_2);
	mul_function(&_2, _0, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_add_function(_5, &_4, &_2 TSRMLS_CC);
	RETURN_MM_DOUBLE(zephir_get_doubleval(_5));

}

PHP_METHOD(PocketMine_Math_Vector3, normalize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3, *_4;
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
	object_init_ex(return_value, pocketmine_math_vector3_ce);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_LONG(_2, 0);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 0);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_LONG(_4, 0);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _2, _3, _4);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector3, dot) {

	zval *v, *_0, *_1, _2 = zval_used_for_init, _3, _4, *_5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v);



	if (!(zephir_instance_of_ev(v, pocketmine_math_vector3_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'v' must be an instance of 'PocketMine\\Math\\Vector3'", "", 0);
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
	ZEPHIR_SINIT_VAR(_4);
	zephir_add_function(&_4, &_2, &_3 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(v, SL("z"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_2);
	mul_function(&_2, _0, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_add_function(_5, &_4, &_2 TSRMLS_CC);
	RETURN_MM_DOUBLE(zephir_get_doubleval(_5));

}

PHP_METHOD(PocketMine_Math_Vector3, cross) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *v, *_0, *_1, _2 = zval_used_for_init, _3 = zval_used_for_init, *_4, *_5, *_6;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &v);



	if (!(zephir_instance_of_ev(v, pocketmine_math_vector3_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'v' must be an instance of 'PocketMine\\Math\\Vector3'", "", 0);
		return;
	}
	object_init_ex(return_value, pocketmine_math_vector3_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(v, SL("z"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	mul_function(&_2, _0, _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(v, SL("y"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	mul_function(&_3, _0, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_sub_function(_4, &_2, &_3 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(v, SL("x"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_2);
	mul_function(&_2, _0, _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(v, SL("z"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_3);
	mul_function(&_3, _0, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_sub_function(_5, &_2, &_3 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(v, SL("y"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_2);
	mul_function(&_2, _0, _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("y"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(v, SL("x"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_3);
	mul_function(&_3, _0, _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	zephir_sub_function(_6, &_2, &_3 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _4, _5, _6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_Vector3, __toString) {

	zval *_1 = NULL, *_3 = NULL, *_5 = NULL;
	zval *_0, *_2, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("x"), PH_NOISY_CC);
	zephir_get_strval(_1, _0);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("y"), PH_NOISY_CC);
	zephir_get_strval(_3, _2);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("z"), PH_NOISY_CC);
	zephir_get_strval(_5, _4);
	ZEPHIR_CONCAT_SVSVSVS(return_value, "Vector3(x=", _1, ",y=", _3, ",y=", _5, ")");
	RETURN_MM();

}

