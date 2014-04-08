
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
#include "kernel/exception.h"
#include "kernel/fcall.h"


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
ZEPHIR_INIT_CLASS(PocketMine_Math_AxisAlignedBB) {

	ZEPHIR_REGISTER_CLASS(PocketMine\\Math, AxisAlignedBB, pocketmine, math_axisalignedbb, pocketmine_math_axisalignedbb_method_entry, 0);

	zend_declare_property_null(pocketmine_math_axisalignedbb_ce, SL("minX"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(pocketmine_math_axisalignedbb_ce, SL("minY"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(pocketmine_math_axisalignedbb_ce, SL("minZ"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(pocketmine_math_axisalignedbb_ce, SL("maxX"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(pocketmine_math_axisalignedbb_ce, SL("maxY"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(pocketmine_math_axisalignedbb_ce, SL("maxZ"), ZEND_ACC_PUBLIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, __construct) {

	zval *minX_param = NULL, *minY_param = NULL, *minZ_param = NULL, *maxX_param = NULL, *maxY_param = NULL, *maxZ_param = NULL, *_0;
	double minX, minY, minZ, maxX, maxY, maxZ;

	zephir_fetch_params(0, 6, 0, &minX_param, &minY_param, &minZ_param, &maxX_param, &maxY_param, &maxZ_param);

	minX = zephir_get_doubleval(minX_param);
	minY = zephir_get_doubleval(minY_param);
	minZ = zephir_get_doubleval(minZ_param);
	maxX = zephir_get_doubleval(maxX_param);
	maxY = zephir_get_doubleval(maxY_param);
	maxZ = zephir_get_doubleval(maxZ_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, minX);
	zephir_update_property_zval(this_ptr, SL("minX"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, minY);
	zephir_update_property_zval(this_ptr, SL("minY"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, minZ);
	zephir_update_property_zval(this_ptr, SL("minZ"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, maxX);
	zephir_update_property_zval(this_ptr, SL("maxX"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, maxY);
	zephir_update_property_zval(this_ptr, SL("maxY"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, maxZ);
	zephir_update_property_zval(this_ptr, SL("maxZ"), _0 TSRMLS_CC);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, setBounds) {

	zval *minX_param = NULL, *minY_param = NULL, *minZ_param = NULL, *maxX_param = NULL, *maxY_param = NULL, *maxZ_param = NULL, *_0;
	double minX, minY, minZ, maxX, maxY, maxZ;

	zephir_fetch_params(0, 6, 0, &minX_param, &minY_param, &minZ_param, &maxX_param, &maxY_param, &maxZ_param);

	minX = zephir_get_doubleval(minX_param);
	minY = zephir_get_doubleval(minY_param);
	minZ = zephir_get_doubleval(minZ_param);
	maxX = zephir_get_doubleval(maxX_param);
	maxY = zephir_get_doubleval(maxY_param);
	maxZ = zephir_get_doubleval(maxZ_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, minX);
	zephir_update_property_zval(this_ptr, SL("minX"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, minY);
	zephir_update_property_zval(this_ptr, SL("minY"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, minZ);
	zephir_update_property_zval(this_ptr, SL("minZ"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, maxX);
	zephir_update_property_zval(this_ptr, SL("maxX"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, maxY);
	zephir_update_property_zval(this_ptr, SL("maxY"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, maxZ);
	zephir_update_property_zval(this_ptr, SL("maxZ"), _0 TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, addCoord) {

	zval *x_param = NULL, *y_param = NULL, *z_param = NULL, *vec = NULL, _0, *_1;
	double x, y, z;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &x_param, &y_param, &z_param);

	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);


	ZEPHIR_SINIT_VAR(_0);
	if (zephir_clone(_0, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(vec, _0);
	if (x < 0) {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZVAL_DOUBLE(_1, x);
		zephir_update_property_zval(vec, SL("minX"), _1 TSRMLS_CC);
	} else {
		if (x > 0) {
			ZEPHIR_INIT_ZVAL_NREF(_1);
			ZVAL_DOUBLE(_1, x);
			zephir_update_property_zval(vec, SL("maxX"), _1 TSRMLS_CC);
		}
	}
	if (y < 0) {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZVAL_DOUBLE(_1, y);
		zephir_update_property_zval(vec, SL("minY"), _1 TSRMLS_CC);
	} else {
		if (y > 0) {
			ZEPHIR_INIT_ZVAL_NREF(_1);
			ZVAL_DOUBLE(_1, y);
			zephir_update_property_zval(vec, SL("maxY"), _1 TSRMLS_CC);
		}
	}
	if (z < 0) {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZVAL_DOUBLE(_1, z);
		zephir_update_property_zval(vec, SL("minZ"), _1 TSRMLS_CC);
	} else {
		if (z > 0) {
			ZEPHIR_INIT_ZVAL_NREF(_1);
			ZVAL_DOUBLE(_1, z);
			zephir_update_property_zval(vec, SL("maxZ"), _1 TSRMLS_CC);
		}
	}
	RETURN_CCTOR(vec);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, expand) {

	zval *x_param = NULL, *y_param = NULL, *z_param = NULL, *vec = NULL, _0, *_1;
	double x, y, z;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &x_param, &y_param, &z_param);

	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);


	ZEPHIR_SINIT_VAR(_0);
	if (zephir_clone(_0, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(vec, _0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, x);
	zephir_update_property_zval(vec, SL("minX"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, y);
	zephir_update_property_zval(vec, SL("minY"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, z);
	zephir_update_property_zval(vec, SL("minZ"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, x);
	zephir_update_property_zval(vec, SL("maxX"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, y);
	zephir_update_property_zval(vec, SL("maxY"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, z);
	zephir_update_property_zval(vec, SL("maxZ"), _1 TSRMLS_CC);
	RETURN_CCTOR(vec);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, offset) {

	zval *x_param = NULL, *y_param = NULL, *z_param = NULL, *vec = NULL, _0, *_1;
	double x, y, z;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &x_param, &y_param, &z_param);

	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);


	ZEPHIR_SINIT_VAR(_0);
	if (zephir_clone(_0, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(vec, _0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, x);
	zephir_update_property_zval(vec, SL("minX"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, y);
	zephir_update_property_zval(vec, SL("minY"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, z);
	zephir_update_property_zval(vec, SL("minZ"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, x);
	zephir_update_property_zval(vec, SL("maxX"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, y);
	zephir_update_property_zval(vec, SL("maxY"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, z);
	zephir_update_property_zval(vec, SL("maxZ"), _1 TSRMLS_CC);
	RETURN_CCTOR(vec);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, contract) {

	zval *x_param = NULL, *y_param = NULL, *z_param = NULL, *vec = NULL, _0, *_1;
	double x, y, z;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &x_param, &y_param, &z_param);

	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);


	ZEPHIR_SINIT_VAR(_0);
	if (zephir_clone(_0, this_ptr TSRMLS_CC) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_CPY_WRT(vec, _0);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, x);
	zephir_update_property_zval(vec, SL("minX"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, y);
	zephir_update_property_zval(vec, SL("minY"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, z);
	zephir_update_property_zval(vec, SL("minZ"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, x);
	zephir_update_property_zval(vec, SL("maxX"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, y);
	zephir_update_property_zval(vec, SL("maxY"), _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_DOUBLE(_1, z);
	zephir_update_property_zval(vec, SL("maxZ"), _1 TSRMLS_CC);
	RETURN_CCTOR(vec);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, setBB) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_13 = NULL;
	zval *bb, *_0, *_1, *_2 = NULL, *_4, *_5, *_6 = NULL, *_7, *_8, *_9 = NULL, *_10, *_11, *_12 = NULL, *_14, *_15, *_16 = NULL, *_17, *_18, *_19 = NULL, *_20, *_21, *_22, *_23, *_24, *_25;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bb);



	if (!(zephir_instance_of_ev(bb, pocketmine_math_axisalignedbb_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bb' must be an instance of 'PocketMine\\Math\\AxisAlignedBB'", "", 0);
		return;
	}
	object_init_ex(return_value, pocketmine_math_axisalignedbb_ce);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(bb, SL("minX"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "min", &_3, _0, _1);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(bb, SL("minY"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_6, "min", &_3, _4, _5);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
	_8 = zephir_fetch_nproperty_this(bb, SL("minZ"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_9, "min", &_3, _7, _8);
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(bb, SL("maxX"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_12, "max", &_13, _10, _11);
	zephir_check_call_status();
	_14 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
	_15 = zephir_fetch_nproperty_this(bb, SL("maxY"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_16, "max", &_13, _14, _15);
	zephir_check_call_status();
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
	_18 = zephir_fetch_nproperty_this(bb, SL("maxZ"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_19, "max", &_13, _17, _18);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_20);
	ZVAL_DOUBLE(_20, zephir_get_doubleval(_2));
	ZEPHIR_INIT_VAR(_21);
	ZVAL_DOUBLE(_21, zephir_get_doubleval(_6));
	ZEPHIR_INIT_VAR(_22);
	ZVAL_DOUBLE(_22, zephir_get_doubleval(_9));
	ZEPHIR_INIT_VAR(_23);
	ZVAL_DOUBLE(_23, zephir_get_doubleval(_12));
	ZEPHIR_INIT_VAR(_24);
	ZVAL_DOUBLE(_24, zephir_get_doubleval(_16));
	ZEPHIR_INIT_VAR(_25);
	ZVAL_DOUBLE(_25, zephir_get_doubleval(_19));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _20, _21, _22, _23, _24, _25);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, getOffsetBoundingBox) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *x_param = NULL, *y_param = NULL, *z_param = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11;
	double x, y, z;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &x_param, &y_param, &z_param);

	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);


	object_init_ex(return_value, pocketmine_math_axisalignedbb_ce);
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property_this(&_0, this_ptr, SL("minX"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("minY"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("minZ"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_3);
	zephir_read_property_this(&_3, this_ptr, SL("maxX"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_4);
	zephir_read_property_this(&_4, this_ptr, SL("maxY"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property_this(&_5, this_ptr, SL("maxZ"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_6);
	ZVAL_DOUBLE(_6, (double) (zephir_get_doubleval(_0) + x));
	ZEPHIR_INIT_VAR(_7);
	ZVAL_DOUBLE(_7, (double) (zephir_get_doubleval(_1) + y));
	ZEPHIR_INIT_VAR(_8);
	ZVAL_DOUBLE(_8, (double) (zephir_get_doubleval(_2) + z));
	ZEPHIR_INIT_VAR(_9);
	ZVAL_DOUBLE(_9, (double) (zephir_get_doubleval(_3) + x));
	ZEPHIR_INIT_VAR(_10);
	ZVAL_DOUBLE(_10, (double) (zephir_get_doubleval(_4) + y));
	ZEPHIR_INIT_VAR(_11);
	ZVAL_DOUBLE(_11, (double) (zephir_get_doubleval(_5) + z));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _6, _7, _8, _9, _10, _11);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, calculateXOffset) {

	zend_bool _2, _7, _10, _16;
	double x, x1, x2;
	zval *bb, *x_param = NULL, *_0, *_1, *_3, *_4, *_5, *_6, *_8, *_9, *_11, *_12, *_13, *_14, *_15 = NULL, *_17, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &bb, &x_param);

	x = zephir_get_doubleval(x_param);


	if (!(zephir_instance_of_ev(bb, pocketmine_math_axisalignedbb_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bb' must be an instance of 'PocketMine\\Math\\AxisAlignedBB'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(bb, SL("maxY"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
	_2 = ZEPHIR_LE(_0, _1);
	if (!(_2)) {
		_3 = zephir_fetch_nproperty_this(bb, SL("minY"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
		_2 = ZEPHIR_GE(_3, _4);
	}
	if (_2) {
		RETURN_MM_DOUBLE(x);
	}
	_5 = zephir_fetch_nproperty_this(bb, SL("maxZ"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
	_7 = ZEPHIR_LE(_5, _6);
	if (!(_7)) {
		_8 = zephir_fetch_nproperty_this(bb, SL("minZ"), PH_NOISY_CC);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
		_7 = ZEPHIR_GE(_8, _9);
	}
	if (_7) {
		RETURN_MM_DOUBLE(x);
	}
	_10 = x > 0;
	if (_10) {
		_11 = zephir_fetch_nproperty_this(bb, SL("maxX"), PH_NOISY_CC);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
		_10 = ZEPHIR_LE(_11, _12);
	}
	if (_10) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(bb, SL("maxX"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_15);
		sub_function(_15, _13, _14 TSRMLS_CC);
		x1 = zephir_get_doubleval(_15);
		if (x1 < x) {
			x = x1;
		}
	}
	_16 = x < 0;
	if (_16) {
		_13 = zephir_fetch_nproperty_this(bb, SL("minX"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
		_16 = ZEPHIR_GE(_13, _14);
	}
	if (_16) {
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
		_18 = zephir_fetch_nproperty_this(bb, SL("minX"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_15);
		sub_function(_15, _17, _18 TSRMLS_CC);
		x2 = zephir_get_doubleval(_15);
		if (x2 > x) {
			x = x2;
		}
	}
	RETURN_MM_DOUBLE(x);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, calculateYOffset) {

	zend_bool _2, _7, _10, _16;
	double y, y1, y2;
	zval *bb, *y_param = NULL, *_0, *_1, *_3, *_4, *_5, *_6, *_8, *_9, *_11, *_12, *_13, *_14, *_15 = NULL, *_17, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &bb, &y_param);

	y = zephir_get_doubleval(y_param);


	if (!(zephir_instance_of_ev(bb, pocketmine_math_axisalignedbb_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bb' must be an instance of 'PocketMine\\Math\\AxisAlignedBB'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(bb, SL("maxX"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
	_2 = ZEPHIR_LE(_0, _1);
	if (!(_2)) {
		_3 = zephir_fetch_nproperty_this(bb, SL("minX"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
		_2 = ZEPHIR_GE(_3, _4);
	}
	if (_2) {
		RETURN_MM_DOUBLE(y);
	}
	_5 = zephir_fetch_nproperty_this(bb, SL("maxZ"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
	_7 = ZEPHIR_LE(_5, _6);
	if (!(_7)) {
		_8 = zephir_fetch_nproperty_this(bb, SL("minZ"), PH_NOISY_CC);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
		_7 = ZEPHIR_GE(_8, _9);
	}
	if (_7) {
		RETURN_MM_DOUBLE(y);
	}
	_10 = y > 0;
	if (_10) {
		_11 = zephir_fetch_nproperty_this(bb, SL("maxY"), PH_NOISY_CC);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
		_10 = ZEPHIR_LE(_11, _12);
	}
	if (_10) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(bb, SL("maxY"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_15);
		sub_function(_15, _13, _14 TSRMLS_CC);
		y1 = zephir_get_doubleval(_15);
		if (y1 < y) {
			y = y1;
		}
	}
	_16 = y < 0;
	if (_16) {
		_13 = zephir_fetch_nproperty_this(bb, SL("minY"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
		_16 = ZEPHIR_GE(_13, _14);
	}
	if (_16) {
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
		_18 = zephir_fetch_nproperty_this(bb, SL("minY"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_15);
		sub_function(_15, _17, _18 TSRMLS_CC);
		y2 = zephir_get_doubleval(_15);
		if (y2 > y) {
			y = y2;
		}
	}
	RETURN_MM_DOUBLE(y);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, calculateZOffset) {

	zend_bool _2, _7, _10, _16;
	double z, z1, z2;
	zval *bb, *z_param = NULL, *_0, *_1, *_3, *_4, *_5, *_6, *_8, *_9, *_11, *_12, *_13, *_14, *_15 = NULL, *_17, *_18;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &bb, &z_param);

	z = zephir_get_doubleval(z_param);


	if (!(zephir_instance_of_ev(bb, pocketmine_math_axisalignedbb_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'bb' must be an instance of 'PocketMine\\Math\\AxisAlignedBB'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(bb, SL("maxX"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
	_2 = ZEPHIR_LE(_0, _1);
	if (!(_2)) {
		_3 = zephir_fetch_nproperty_this(bb, SL("minX"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
		_2 = ZEPHIR_GE(_3, _4);
	}
	if (_2) {
		RETURN_MM_DOUBLE(z);
	}
	_5 = zephir_fetch_nproperty_this(bb, SL("maxY"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
	_7 = ZEPHIR_LE(_5, _6);
	if (!(_7)) {
		_8 = zephir_fetch_nproperty_this(bb, SL("minY"), PH_NOISY_CC);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
		_7 = ZEPHIR_GE(_8, _9);
	}
	if (_7) {
		RETURN_MM_DOUBLE(z);
	}
	_10 = z > 0;
	if (_10) {
		_11 = zephir_fetch_nproperty_this(bb, SL("maxZ"), PH_NOISY_CC);
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
		_10 = ZEPHIR_LE(_11, _12);
	}
	if (_10) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(bb, SL("maxZ"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_15);
		sub_function(_15, _13, _14 TSRMLS_CC);
		z1 = zephir_get_doubleval(_15);
		if (z1 < z) {
			z = z1;
		}
	}
	_16 = z < 0;
	if (_16) {
		_13 = zephir_fetch_nproperty_this(bb, SL("minZ"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
		_16 = ZEPHIR_GE(_13, _14);
	}
	if (_16) {
		_17 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
		_18 = zephir_fetch_nproperty_this(bb, SL("minZ"), PH_NOISY_CC);
		ZEPHIR_INIT_LNVAR(_15);
		sub_function(_15, _17, _18 TSRMLS_CC);
		z2 = zephir_get_doubleval(_15);
		if (z2 > z) {
			z = z2;
		}
	}
	RETURN_MM_DOUBLE(z);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, intersectsWith) {

	zend_bool _2, _7, _12;
	zval *bb, *_0, *_1, *_3, *_4, *_5, *_6, *_8, *_9, *_10, *_11, *_13, *_14;

	zephir_fetch_params(0, 1, 0, &bb);



	if (!(zephir_instance_of_ev(bb, pocketmine_math_axisalignedbb_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Parameter 'bb' must be an instance of 'PocketMine\\Math\\AxisAlignedBB'", "", 0);
		return;
	}
	_0 = zephir_fetch_nproperty_this(bb, SL("maxX"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
	_2 = ZEPHIR_LE(_0, _1);
	if (!(_2)) {
		_3 = zephir_fetch_nproperty_this(bb, SL("minX"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
		_2 = ZEPHIR_GE(_3, _4);
	}
	if (_2) {
		RETURN_BOOL(0);
	}
	_5 = zephir_fetch_nproperty_this(bb, SL("maxY"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
	_7 = ZEPHIR_LE(_5, _6);
	if (!(_7)) {
		_8 = zephir_fetch_nproperty_this(bb, SL("minY"), PH_NOISY_CC);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
		_7 = ZEPHIR_GE(_8, _9);
	}
	if (_7) {
		RETURN_BOOL(0);
	}
	_10 = zephir_fetch_nproperty_this(bb, SL("maxZ"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
	_12 = ZEPHIR_GT(_10, _11);
	if (_12) {
		_13 = zephir_fetch_nproperty_this(bb, SL("minZ"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
		_12 = ZEPHIR_LT(_13, _14);
	}
	RETURN_BOOL(_12);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, isVectorInside) {

	zend_bool _2, _7, _12;
	zval *vector, *_0, *_1, *_3, *_4, *_5, *_6, *_8, *_9, *_10, *_11, *_13, *_14;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vector);



	if (!(zephir_instance_of_ev(vector, pocketmine_math_vector3_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'vector' must be an instance of 'PocketMine\\Math\\Vector3'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, vector, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
	_2 = ZEPHIR_LE(_0, _1);
	if (!(_2)) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, vector, SL("x"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
		_2 = ZEPHIR_GE(_3, _4);
	}
	if (_2) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(_5);
	zephir_read_property(&_5, vector, SL("y"), PH_NOISY_CC);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
	_7 = ZEPHIR_LE(_5, _6);
	if (!(_7)) {
		ZEPHIR_OBS_VAR(_8);
		zephir_read_property(&_8, vector, SL("y"), PH_NOISY_CC);
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
		_7 = ZEPHIR_GE(_8, _9);
	}
	if (_7) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property(&_10, vector, SL("z"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
	_12 = ZEPHIR_GT(_10, _11);
	if (_12) {
		ZEPHIR_OBS_VAR(_13);
		zephir_read_property(&_13, vector, SL("z"), PH_NOISY_CC);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
		_12 = ZEPHIR_LT(_13, _14);
	}
	RETURN_MM_BOOL(_12);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, getAverageEdgeLength) {

	zval *_0, *_1, _2 = zval_used_for_init, _3 = zval_used_for_init, *_4;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	sub_function(&_2, _0, _1 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	zephir_add_function(&_3, &_2, _0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_2);
	sub_function(&_2, &_3, _0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_3);
	zephir_add_function(&_3, &_2, _0 TSRMLS_CC);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	sub_function(_4, &_3, _0 TSRMLS_CC);
	RETURN_MM_DOUBLE((zephir_get_doubleval(_4) / 3.0));

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, isVectorInYZ) {

	zend_bool _2, _5, _8;
	zval *vector, *_0, *_1, *_3, *_4, *_6, *_7, *_9, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vector);



	if (!(zephir_instance_of_ev(vector, pocketmine_math_vector3_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'vector' must be an instance of 'PocketMine\\Math\\Vector3'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, vector, SL("y"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
	_2 = ZEPHIR_GE(_0, _1);
	if (_2) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, vector, SL("y"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
		_2 = ZEPHIR_LE(_3, _4);
	}
	_5 = _2;
	if (_5) {
		ZEPHIR_OBS_VAR(_6);
		zephir_read_property(&_6, vector, SL("z"), PH_NOISY_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
		_5 = ZEPHIR_GE(_6, _7);
	}
	_8 = _5;
	if (_8) {
		ZEPHIR_OBS_VAR(_9);
		zephir_read_property(&_9, vector, SL("z"), PH_NOISY_CC);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
		_8 = ZEPHIR_LE(_9, _10);
	}
	RETURN_MM_BOOL(_8);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, isVectorInXZ) {

	zend_bool _2, _5, _8;
	zval *vector, *_0, *_1, *_3, *_4, *_6, *_7, *_9, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vector);



	if (!(zephir_instance_of_ev(vector, pocketmine_math_vector3_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'vector' must be an instance of 'PocketMine\\Math\\Vector3'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, vector, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
	_2 = ZEPHIR_GE(_0, _1);
	if (_2) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, vector, SL("x"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
		_2 = ZEPHIR_LE(_3, _4);
	}
	_5 = _2;
	if (_5) {
		ZEPHIR_OBS_VAR(_6);
		zephir_read_property(&_6, vector, SL("z"), PH_NOISY_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("minZ"), PH_NOISY_CC);
		_5 = ZEPHIR_GE(_6, _7);
	}
	_8 = _5;
	if (_8) {
		ZEPHIR_OBS_VAR(_9);
		zephir_read_property(&_9, vector, SL("z"), PH_NOISY_CC);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("maxZ"), PH_NOISY_CC);
		_8 = ZEPHIR_LE(_9, _10);
	}
	RETURN_MM_BOOL(_8);

}

PHP_METHOD(PocketMine_Math_AxisAlignedBB, isVectorInXY) {

	zend_bool _2, _5, _8;
	zval *vector, *_0, *_1, *_3, *_4, *_6, *_7, *_9, *_10;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &vector);



	if (!(zephir_instance_of_ev(vector, pocketmine_math_vector3_ce TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Parameter 'vector' must be an instance of 'PocketMine\\Math\\Vector3'", "", 0);
		return;
	}
	ZEPHIR_OBS_VAR(_0);
	zephir_read_property(&_0, vector, SL("x"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("minX"), PH_NOISY_CC);
	_2 = ZEPHIR_GE(_0, _1);
	if (_2) {
		ZEPHIR_OBS_VAR(_3);
		zephir_read_property(&_3, vector, SL("x"), PH_NOISY_CC);
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("maxX"), PH_NOISY_CC);
		_2 = ZEPHIR_LE(_3, _4);
	}
	_5 = _2;
	if (_5) {
		ZEPHIR_OBS_VAR(_6);
		zephir_read_property(&_6, vector, SL("y"), PH_NOISY_CC);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("minY"), PH_NOISY_CC);
		_5 = ZEPHIR_GE(_6, _7);
	}
	_8 = _5;
	if (_8) {
		ZEPHIR_OBS_VAR(_9);
		zephir_read_property(&_9, vector, SL("y"), PH_NOISY_CC);
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("maxY"), PH_NOISY_CC);
		_8 = ZEPHIR_LE(_9, _10);
	}
	RETURN_MM_BOOL(_8);

}

