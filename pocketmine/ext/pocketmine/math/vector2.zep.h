
extern zend_class_entry *pocketmine_math_vector2_ce;

ZEPHIR_INIT_CLASS(PocketMine_Math_Vector2);

PHP_METHOD(PocketMine_Math_Vector2, __construct);
PHP_METHOD(PocketMine_Math_Vector2, getX);
PHP_METHOD(PocketMine_Math_Vector2, getY);
PHP_METHOD(PocketMine_Math_Vector2, getFloorX);
PHP_METHOD(PocketMine_Math_Vector2, getFloorY);
PHP_METHOD(PocketMine_Math_Vector2, add);
PHP_METHOD(PocketMine_Math_Vector2, subtract);
PHP_METHOD(PocketMine_Math_Vector2, ceil);
PHP_METHOD(PocketMine_Math_Vector2, floor);
PHP_METHOD(PocketMine_Math_Vector2, round);
PHP_METHOD(PocketMine_Math_Vector2, abs);
PHP_METHOD(PocketMine_Math_Vector2, multiply);
PHP_METHOD(PocketMine_Math_Vector2, divide);
PHP_METHOD(PocketMine_Math_Vector2, distance);
PHP_METHOD(PocketMine_Math_Vector2, distanceSquared);
PHP_METHOD(PocketMine_Math_Vector2, length);
PHP_METHOD(PocketMine_Math_Vector2, lengthSquared);
PHP_METHOD(PocketMine_Math_Vector2, normalize);
PHP_METHOD(PocketMine_Math_Vector2, dot);
PHP_METHOD(PocketMine_Math_Vector2, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector2___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector2_add, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector2_subtract, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector2_multiply, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector2_divide, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector2_distance, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector2_distancesquared, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector2_dot, 0, 0, 1)
	ZEND_ARG_INFO(0, v)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pocketmine_math_vector2_method_entry) {
	PHP_ME(PocketMine_Math_Vector2, __construct, arginfo_pocketmine_math_vector2___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PocketMine_Math_Vector2, getX, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, getY, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, getFloorX, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, getFloorY, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, add, arginfo_pocketmine_math_vector2_add, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, subtract, arginfo_pocketmine_math_vector2_subtract, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, ceil, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, floor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, round, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, abs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, multiply, arginfo_pocketmine_math_vector2_multiply, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, divide, arginfo_pocketmine_math_vector2_divide, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, distance, arginfo_pocketmine_math_vector2_distance, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, distanceSquared, arginfo_pocketmine_math_vector2_distancesquared, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, length, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, lengthSquared, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, normalize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, dot, arginfo_pocketmine_math_vector2_dot, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector2, __toString, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
