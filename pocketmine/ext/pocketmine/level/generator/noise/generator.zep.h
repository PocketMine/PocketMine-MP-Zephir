
extern zend_class_entry *pocketmine_level_generator_noise_generator_ce;

ZEPHIR_INIT_CLASS(PocketMine_Level_Generator_Noise_Generator);

PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, floor);
PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, fade);
PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, lerp);
PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, grad);
PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, getNoise2D);
PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, getNoise3D);
PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, noise2D);
PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, noise3D);
PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, setOffset);
PHP_METHOD(PocketMine_Level_Generator_Noise_Generator, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_level_generator_noise_generator_floor, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_level_generator_noise_generator_fade, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_level_generator_noise_generator_lerp, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_level_generator_noise_generator_grad, 0, 0, 4)
	ZEND_ARG_INFO(0, hash)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_level_generator_noise_generator_getnoise2d, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_level_generator_noise_generator_getnoise3d, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_level_generator_noise_generator_noise2d, 0, 0, 2)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, z)
	ZEND_ARG_INFO(0, normalized)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_level_generator_noise_generator_noise3d, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
	ZEND_ARG_INFO(0, normalized)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_level_generator_noise_generator_setoffset, 0, 0, 3)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, y)
	ZEND_ARG_INFO(0, z)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pocketmine_level_generator_noise_generator_method_entry) {
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, floor, arginfo_pocketmine_level_generator_noise_generator_floor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, fade, arginfo_pocketmine_level_generator_noise_generator_fade, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, lerp, arginfo_pocketmine_level_generator_noise_generator_lerp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, grad, arginfo_pocketmine_level_generator_noise_generator_grad, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, getNoise2D, arginfo_pocketmine_level_generator_noise_generator_getnoise2d, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, getNoise3D, arginfo_pocketmine_level_generator_noise_generator_getnoise3d, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, noise2D, arginfo_pocketmine_level_generator_noise_generator_noise2d, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, noise3D, arginfo_pocketmine_level_generator_noise_generator_noise3d, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, setOffset, arginfo_pocketmine_level_generator_noise_generator_setoffset, ZEND_ACC_PUBLIC)
	PHP_ME(PocketMine_Level_Generator_Noise_Generator, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
  PHP_FE_END
};
