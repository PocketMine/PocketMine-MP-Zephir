
extern zend_class_entry *pocketmine_utils_random_ce;

ZEPHIR_INIT_CLASS(PocketMine_Utils_Random);

PHP_METHOD(PocketMine_Utils_Random, __construct);
PHP_METHOD(PocketMine_Utils_Random, setSeed);
PHP_METHOD(PocketMine_Utils_Random, nextInt);
PHP_METHOD(PocketMine_Utils_Random, nextSignedInt);
PHP_METHOD(PocketMine_Utils_Random, nextFloat);
PHP_METHOD(PocketMine_Utils_Random, nextSignedFloat);
PHP_METHOD(PocketMine_Utils_Random, nextBoolean);
PHP_METHOD(PocketMine_Utils_Random, nextRange);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_random___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, seed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_random_setseed, 0, 0, 1)
	ZEND_ARG_INFO(0, seed)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_random_nextrange, 0, 0, 0)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pocketmine_utils_random_method_entry) {
	PHP_ME(PocketMine_Utils_Random, __construct, arginfo_pocketmine_utils_random___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PocketMine_Utils_Random, setSeed, arginfo_pocketmine_utils_random_setseed, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Utils_Random, nextInt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Utils_Random, nextSignedInt, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Utils_Random, nextFloat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Utils_Random, nextSignedFloat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Utils_Random, nextBoolean, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Utils_Random, nextRange, arginfo_pocketmine_utils_random_nextrange, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
