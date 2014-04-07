
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * Unsecure Random Number Generator, used for fast seeded values
 */
ZEPHIR_INIT_CLASS(PocketMine_Utils_Random) {

	ZEPHIR_REGISTER_CLASS(PocketMine\\Utils, Random, pocketmine, utils_random, pocketmine_utils_random_method_entry, 0);

	zend_declare_property_long(pocketmine_utils_random_ce, SL("z"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(pocketmine_utils_random_ce, SL("w"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * @param int $seed Integer to be used as seed.
 */
PHP_METHOD(PocketMine_Utils_Random, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *seed_param = NULL, *_0;
	long seed;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &seed_param);

	if (!seed_param) {
		seed = 0;
	} else {
		seed = zephir_get_intval(seed_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_LONG(_0, seed);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setseed", NULL, _0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param int $seed Integer to be used as seed.
 */
PHP_METHOD(PocketMine_Utils_Random, setSeed) {

	zval *seed_param = NULL, *_0;
	long seed;

	zephir_fetch_params(0, 1, 0, &seed_param);

	seed = zephir_get_intval(seed_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, (seed ^ 0xdeadbeef));
	zephir_update_property_this(this_ptr, SL("z"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, (seed ^ 0xc0de1337));
	zephir_update_property_this(this_ptr, SL("w"), _0 TSRMLS_CC);

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
	RETURN_MM_LONG(((int) (zephir_get_numberval(_0)) & 0x7fffffff));

}

/**
 * Returns a 32-bit integer (signed)
 *
 * @return int
 */
PHP_METHOD(PocketMine_Utils_Random, nextSignedInt) {

	zval *_0, *_1, *_2, *_3, *_4, *_5;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(_2, ((36969 * (((int) (zephir_get_numberval(_0)) & 65535))) + ((zephir_get_numberval(_1) * 65536))));
	zephir_update_property_this(this_ptr, SL("z"), _2 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("w"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("w"), PH_NOISY_CC);
	ZEPHIR_INIT_ZVAL_NREF(_4);
	ZVAL_LONG(_4, ((18000 * (((int) (zephir_get_numberval(_2)) & 65535))) + ((zephir_get_numberval(_3) * 65536))));
	zephir_update_property_this(this_ptr, SL("w"), _4 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("z"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("w"), PH_NOISY_CC);
	RETURN_LONG(((zephir_get_numberval(_4) * 65536) + zephir_get_numberval(_5)));

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
	RETURN_MM_BOOL(ZEPHIR_GE_LONG(_0, 0));

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

