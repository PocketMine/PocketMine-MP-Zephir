
extern zend_class_entry *pocketmine_math_axisalignedbb_ce;

ZEPHIR_INIT_CLASS(PocketMine_Math_AxisAlignedBB);

PHP_METHOD(PocketMine_Math_AxisAlignedBB, __construct);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, setBounds);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, addCoord);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, expand);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, offset);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, contract);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, setBB);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, getOffsetBoundingBox);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, calculateXOffset);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, calculateYOffset);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, calculateZOffset);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, intersectsWith);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, isVectorInside);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, getAverageEdgeLength);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, isVectorInYZ);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, isVectorInXZ);
PHP_METHOD(PocketMine_Math_AxisAlignedBB, isVectorInXY);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb___construct, 0, 0, 6)
	ZEND_ARG_INFO(0, minX)
	ZEND_ARG_INFO(0, minY)
	ZEND_ARG_INFO(0, minZ)
	ZEND_ARG_INFO(0, maxX)
	ZEND_ARG_INFO(0, maxY)
	ZEND_ARG_INFO(0, maxZ)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_setbounds, 0, 0, 6)
	ZEND_ARG_INFO(0, minX)
	ZEND_ARG_INFO(0, minY)
	ZEND_ARG_INFO(0, minZ)
	ZEND_ARG_INFO(0, maxX)
	ZEND_ARG_INFO(0, maxY)
	ZEND_ARG_INFO(0, maxZ)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_addcoord, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_expand, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_offset, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_contract, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_setbb, 0, 0, 1)
	ZEND_ARG_INFO(0, bb)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_getoffsetboundingbox, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_calculatexoffset, 0, 0, 2)
	ZEND_ARG_INFO(0, bb)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_calculateyoffset, 0, 0, 2)
	ZEND_ARG_INFO(0, bb)
	ZEND_ARG_INFO(0, y)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_calculatezoffset, 0, 0, 2)
	ZEND_ARG_INFO(0, bb)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_intersectswith, 0, 0, 1)
	ZEND_ARG_INFO(0, bb)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_isvectorinside, 0, 0, 1)
	ZEND_ARG_INFO(0, vector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_isvectorinyz, 0, 0, 1)
	ZEND_ARG_INFO(0, vector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_isvectorinxz, 0, 0, 1)
	ZEND_ARG_INFO(0, vector)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_math_axisalignedbb_isvectorinxy, 0, 0, 1)
	ZEND_ARG_INFO(0, vector)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pocketmine_math_axisalignedbb_method_entry) {
	PHP_ME(PocketMine_Math_AxisAlignedBB, __construct, arginfo_pocketmine_math_axisalignedbb___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PocketMine_Math_AxisAlignedBB, setBounds, arginfo_pocketmine_math_axisalignedbb_setbounds, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, addCoord, arginfo_pocketmine_math_axisalignedbb_addcoord, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, expand, arginfo_pocketmine_math_axisalignedbb_expand, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, offset, arginfo_pocketmine_math_axisalignedbb_offset, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, contract, arginfo_pocketmine_math_axisalignedbb_contract, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, setBB, arginfo_pocketmine_math_axisalignedbb_setbb, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, getOffsetBoundingBox, arginfo_pocketmine_math_axisalignedbb_getoffsetboundingbox, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, calculateXOffset, arginfo_pocketmine_math_axisalignedbb_calculatexoffset, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, calculateYOffset, arginfo_pocketmine_math_axisalignedbb_calculateyoffset, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, calculateZOffset, arginfo_pocketmine_math_axisalignedbb_calculatezoffset, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, intersectsWith, arginfo_pocketmine_math_axisalignedbb_intersectswith, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, isVectorInside, arginfo_pocketmine_math_axisalignedbb_isvectorinside, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, getAverageEdgeLength, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, isVectorInYZ, arginfo_pocketmine_math_axisalignedbb_isvectorinyz, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, isVectorInXZ, arginfo_pocketmine_math_axisalignedbb_isvectorinxz, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Math_AxisAlignedBB, isVectorInXY, arginfo_pocketmine_math_axisalignedbb_isvectorinxy, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
