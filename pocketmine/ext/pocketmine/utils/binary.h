
extern zend_class_entry *pocketmine_utils_binary_ce;

ZEPHIR_INIT_CLASS(PocketMine_Utils_Binary);

PHP_METHOD(PocketMine_Utils_Binary, readTriad);
PHP_METHOD(PocketMine_Utils_Binary, writeTriad);
PHP_METHOD(PocketMine_Utils_Binary, writeMetadata);
PHP_METHOD(PocketMine_Utils_Binary, readMetadata);
PHP_METHOD(PocketMine_Utils_Binary, readBool);
PHP_METHOD(PocketMine_Utils_Binary, writeBool);
PHP_METHOD(PocketMine_Utils_Binary, readByte);
PHP_METHOD(PocketMine_Utils_Binary, writeByte);
PHP_METHOD(PocketMine_Utils_Binary, readShort);
PHP_METHOD(PocketMine_Utils_Binary, writeShort);
PHP_METHOD(PocketMine_Utils_Binary, readLShort);
PHP_METHOD(PocketMine_Utils_Binary, writeLShort);
PHP_METHOD(PocketMine_Utils_Binary, readInt);
PHP_METHOD(PocketMine_Utils_Binary, writeInt);
PHP_METHOD(PocketMine_Utils_Binary, readLInt);
PHP_METHOD(PocketMine_Utils_Binary, writeLInt);
PHP_METHOD(PocketMine_Utils_Binary, readFloat);
PHP_METHOD(PocketMine_Utils_Binary, writeFloat);
PHP_METHOD(PocketMine_Utils_Binary, readLFloat);
PHP_METHOD(PocketMine_Utils_Binary, writeLFloat);
PHP_METHOD(PocketMine_Utils_Binary, printFloat);
PHP_METHOD(PocketMine_Utils_Binary, readDouble);
PHP_METHOD(PocketMine_Utils_Binary, writeDouble);
PHP_METHOD(PocketMine_Utils_Binary, readLDouble);
PHP_METHOD(PocketMine_Utils_Binary, writeLDouble);
PHP_METHOD(PocketMine_Utils_Binary, readLong);
PHP_METHOD(PocketMine_Utils_Binary, writeLong);
PHP_METHOD(PocketMine_Utils_Binary, readLLong);
PHP_METHOD(PocketMine_Utils_Binary, writeLLong);

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readtriad, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writetriad, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writemetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readmetadata, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, types)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readbool, 0, 0, 1)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writebool, 0, 0, 1)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readbyte, 0, 0, 1)
	ZEND_ARG_INFO(0, c)
	ZEND_ARG_INFO(0, isSigned)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writebyte, 0, 0, 1)
	ZEND_ARG_INFO(0, c)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readshort, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, isSigned)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writeshort, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readlshort, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
	ZEND_ARG_INFO(0, isSigned)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writelshort, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readint, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writeint, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readlint, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writelint, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readfloat, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writefloat, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readlfloat, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writelfloat, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_printfloat, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readdouble, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writedouble, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readldouble, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writeldouble, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readlong, 0, 0, 1)
	ZEND_ARG_INFO(0, x)
	ZEND_ARG_INFO(0, isSigned)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writelong, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_readllong, 0, 0, 1)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_pocketmine_utils_binary_writellong, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(pocketmine_utils_binary_method_entry) {
	PHP_ME(PocketMine_Utils_Binary, readTriad, arginfo_pocketmine_utils_binary_readtriad, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeTriad, arginfo_pocketmine_utils_binary_writetriad, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeMetadata, arginfo_pocketmine_utils_binary_writemetadata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readMetadata, arginfo_pocketmine_utils_binary_readmetadata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readBool, arginfo_pocketmine_utils_binary_readbool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeBool, arginfo_pocketmine_utils_binary_writebool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readByte, arginfo_pocketmine_utils_binary_readbyte, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeByte, arginfo_pocketmine_utils_binary_writebyte, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readShort, arginfo_pocketmine_utils_binary_readshort, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeShort, arginfo_pocketmine_utils_binary_writeshort, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readLShort, arginfo_pocketmine_utils_binary_readlshort, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeLShort, arginfo_pocketmine_utils_binary_writelshort, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readInt, arginfo_pocketmine_utils_binary_readint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeInt, arginfo_pocketmine_utils_binary_writeint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readLInt, arginfo_pocketmine_utils_binary_readlint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeLInt, arginfo_pocketmine_utils_binary_writelint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readFloat, arginfo_pocketmine_utils_binary_readfloat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeFloat, arginfo_pocketmine_utils_binary_writefloat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readLFloat, arginfo_pocketmine_utils_binary_readlfloat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeLFloat, arginfo_pocketmine_utils_binary_writelfloat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, printFloat, arginfo_pocketmine_utils_binary_printfloat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readDouble, arginfo_pocketmine_utils_binary_readdouble, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeDouble, arginfo_pocketmine_utils_binary_writedouble, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readLDouble, arginfo_pocketmine_utils_binary_readldouble, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeLDouble, arginfo_pocketmine_utils_binary_writeldouble, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readLong, arginfo_pocketmine_utils_binary_readlong, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeLong, arginfo_pocketmine_utils_binary_writelong, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, readLLong, arginfo_pocketmine_utils_binary_readllong, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PocketMine_Utils_Binary, writeLLong, arginfo_pocketmine_utils_binary_writellong, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
