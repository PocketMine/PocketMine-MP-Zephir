
extern zend_class_entry *pocketmine_math_vector3_ce;

ZEPHIR_INIT_CLASS(PocketMine_Math_Vector3);

PHP_METHOD(PocketMine_Math_Vector3, __construct);
PHP_METHOD(PocketMine_Math_Vector3, getX);
PHP_METHOD(PocketMine_Math_Vector3, getY);
PHP_METHOD(PocketMine_Math_Vector3, getZ);
PHP_METHOD(PocketMine_Math_Vector3, getFloorX);
PHP_METHOD(PocketMine_Math_Vector3, getFloorY);
PHP_METHOD(PocketMine_Math_Vector3, getFloorZ);
PHP_METHOD(PocketMine_Math_Vector3, getRight);
PHP_METHOD(PocketMine_Math_Vector3, getUp);
PHP_METHOD(PocketMine_Math_Vector3, getForward);
PHP_METHOD(PocketMine_Math_Vector3, getSouth);
PHP_METHOD(PocketMine_Math_Vector3, getWest);
PHP_METHOD(PocketMine_Math_Vector3, add);
PHP_METHOD(PocketMine_Math_Vector3, subtract);
PHP_METHOD(PocketMine_Math_Vector3, ceil);
PHP_METHOD(PocketMine_Math_Vector3, floor);
PHP_METHOD(PocketMine_Math_Vector3, round);
PHP_METHOD(PocketMine_Math_Vector3, abs);
PHP_METHOD(PocketMine_Math_Vector3, multiply);
PHP_METHOD(PocketMine_Math_Vector3, divide);
PHP_METHOD(PocketMine_Math_Vector3, getSide);
PHP_METHOD(PocketMine_Math_Vector3, distance);
PHP_METHOD(PocketMine_Math_Vector3, distanceSquared);
PHP_METHOD(PocketMine_Math_Vector3, maxPlainDistance);
PHP_METHOD(PocketMine_Math_Vector3, length);
PHP_METHOD(PocketMine_Math_Vector3, lengthSquared);
PHP_METHOD(PocketMine_Math_Vector3, normalize);
PHP_METHOD(PocketMine_Math_Vector3, dot);
PHP_METHOD(PocketMine_Math_Vector3, cross);
PHP_METHOD(PocketMine_Math_Vector3, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_add, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_subtract, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_multiply, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_divide, 0, 0, 1)
	ZEND_ARG_INFO(0, number)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_getside, 0, 0, 1)
	ZEND_ARG_INFO(0, side)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_distance, 0, 0, 1)
	ZEND_ARG_INFO(0, pos)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_distancesquared, 0, 0, 1)
	ZEND_ARG_INFO(0, pos)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_maxplaindistance, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_dot, 0, 0, 1)
	ZEND_ARG_INFO(0, v)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_vector3_cross, 0, 0, 1)
	ZEND_ARG_INFO(0, v)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pocketmine_math_vector3_method_entry) {
	PHP_ME(PocketMine_Math_Vector3, __construct, arginfo_pocketmine_math_vector3___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PocketMine_Math_Vector3, getX, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getY, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getZ, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getFloorX, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getFloorY, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getFloorZ, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getRight, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getUp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getForward, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getSouth, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getWest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, add, arginfo_pocketmine_math_vector3_add, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, subtract, arginfo_pocketmine_math_vector3_subtract, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, ceil, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, floor, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, round, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, abs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, multiply, arginfo_pocketmine_math_vector3_multiply, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, divide, arginfo_pocketmine_math_vector3_divide, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, getSide, arginfo_pocketmine_math_vector3_getside, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, distance, arginfo_pocketmine_math_vector3_distance, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, distanceSquared, arginfo_pocketmine_math_vector3_distancesquared, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, maxPlainDistance, arginfo_pocketmine_math_vector3_maxplaindistance, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, length, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, lengthSquared, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, normalize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, dot, arginfo_pocketmine_math_vector3_dot, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, cross, arginfo_pocketmine_math_vector3_cross, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_Vector3, __toString, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
