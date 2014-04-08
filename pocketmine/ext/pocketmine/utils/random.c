
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
#include "kernel/operators.h"
#include "kernel/object.h"


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
/**
 * Unsecure Random Number Generator, used for fast seeded values
 */
ZEPHIR_INIT_CLASS(PocketMine_Utils_Random) {

	ZEPHIR_REGISTER_CLASS(PocketMine\\Utils, Random, pocketmine, utils_random, pocketmine_utils_random_method_entry, 0);

	zend_declare_property_null(pocketmine_utils_random_ce, SL("seed"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param int $seed Integer to be used as seed.
 */
PHP_METHOD(PocketMine_Utils_Random, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *seed_param = NULL, *_0 = NULL, *_1;
	long seed;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &seed_param);

	if (!seed_param) {
		seed = -1;
	} else {
		seed = zephir_get_intval(seed_param);
	}


	if (seed == -1) {
		ZEPHIR_CALL_FUNCTION(&_0, "time", NULL);
		zephir_check_call_status();
		seed = zephir_get_intval(_0);
	}
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, seed);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setseed", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param int $seed Integer to be used as seed.
 */
PHP_METHOD(PocketMine_Utils_Random, setSeed) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *seed_param = NULL, *_0 = NULL, *_2, *_3 = NULL, *_5;
	long seed;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &seed_param);

	seed = zephir_get_intval(seed_param);


	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, seed);
	ZEPHIR_CALL_CE_STATIC(&_0, pocketmine_utils_binary_ce, "writeint", &_1, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "crc32", &_4, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_ZVAL_NREF(_5);
	ZVAL_LONG(_5, zephir_get_intval(_3));
	zephir_update_property_this(this_ptr, SL("seed"), _5 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an 31-bit integer (not signed)
 *
 * @return int
 */
PHP_METHOD(PocketMine_Utils_Random, nextInt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "nextsignedint",  NULL);
	zephir_check_call_status();
	RETURN_MM_LONG((zephir_get_intval(_0) & 0x7fffffff));

}

/**
 * Returns a 32-bit integer (signed)
 *
 * @return int
 */
PHP_METHOD(PocketMine_Utils_Random, nextSignedInt) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval *_0 = NULL, *_2, *_3 = NULL, *_5, *_6;
	long t;

	ZEPHIR_MM_GROW();

	_2 = zephir_fetch_nproperty_this(this_ptr, SL("seed"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_0, pocketmine_utils_binary_ce, "writeint", &_1, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "crc32", &_4, _0);
	zephir_check_call_status();
	t = zephir_get_intval(_3);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("seed"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_6);
	ZVAL_LONG(_6, ((int) (zephir_get_numberval(_5)) ^ t));
	zephir_update_property_this(this_ptr, SL("seed"), _6 TSRMLS_CC);
	if (t > 2147483647) {
		t -= 4294967296;
	}
	RETURN_MM_LONG(t);

}

/**
 * Returns a float between 0.0 and 1.0 (inclusive)
 *
 * @return float
 */
PHP_METHOD(PocketMine_Utils_Random, nextFloat) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "nextint",  NULL);
	zephir_check_call_status();
	RETURN_MM_DOUBLE((zephir_get_doubleval(_0) / 2147483647.0));

}

/**
 * Returns a float between -1.0 and 1.0 (inclusive)
 *
 * @return float
 */
PHP_METHOD(PocketMine_Utils_Random, nextSignedFloat) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "nextsignedint",  NULL);
	zephir_check_call_status();
	RETURN_MM_DOUBLE((zephir_get_doubleval(_0) / 2147483647.0));

}

/**
 * Returns a random boolean
 *
 * @return bool
 */
PHP_METHOD(PocketMine_Utils_Random, nextBoolean) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "nextsignedint",  NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(zephir_get_intval(_0) >= 0);

}

/**
 * Returns a random integer between $start and $end
 *
 * @param int $start default 0
 * @param int $end   default 0x7fffffff
 *
 * @return int
 */
PHP_METHOD(PocketMine_Utils_Random, nextRange) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *start_param = NULL, *end_param = NULL, *_0 = NULL;
	long start, end;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &start_param, &end_param);

	if (!start_param) {
		start = 0;
	} else {
		start = zephir_get_intval(start_param);
	}
	if (!end_param) {
		end = 0x7fffffff;
	} else {
		end = zephir_get_intval(end_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "nextint",  NULL);
	zephir_check_call_status();
	RETURN_MM_LONG((start + (zephir_get_intval(_0) % (((end + 1) - start)))));

}

