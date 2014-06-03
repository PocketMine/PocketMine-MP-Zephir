
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_POCKETMINE_H
#define PHP_POCKETMINE_H 1

#define ZEPHIR_RELEASE 1

#include "kernel/globals.h"

#define PHP_POCKETMINE_NAME        "pocketmine"
#define PHP_POCKETMINE_VERSION     "0.0.2"
#define PHP_POCKETMINE_EXTNAME     "pocketmine"
#define PHP_POCKETMINE_AUTHOR      "PocketMine Team"
#define PHP_POCKETMINE_ZEPVERSION  "0.4.2a"
#define PHP_POCKETMINE_DESCRIPTION "Optional extension that implements parts of PocketMine-MP in a fast PHP extension "



ZEND_BEGIN_MODULE_GLOBALS(pocketmine)

	/* Memory */
	zephir_memory_entry *start_memory; /**< The first preallocated frame */
	zephir_memory_entry *end_memory; /**< The last preallocate frame */
	zephir_memory_entry *active_memory; /**< The current memory frame */

	/* Virtual Symbol Tables */
	zephir_symbol_table *active_symbol_table;

	/** Function cache */
	HashTable *fcache;

	/* Max recursion control */
	unsigned int recursive_lock;

	/* Global constants */
	zval *global_true;
	zval *global_false;
	zval *global_null;
	
ZEND_END_MODULE_GLOBALS(pocketmine)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(pocketmine)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) TSRMG(pocketmine_globals_id, zend_pocketmine_globals *, v)
#else
	#define ZEPHIR_GLOBAL(v) (pocketmine_globals.v)
#endif

#ifdef ZTS
	#define ZEPHIR_VGLOBAL ((zend_pocketmine_globals *) (*((void ***) tsrm_ls))[TSRM_UNSHUFFLE_RSRC_ID(pocketmine_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(pocketmine_globals)
#endif

#define zephir_globals_def pocketmine_globals
#define zend_zephir_globals_def zend_pocketmine_globals

extern zend_module_entry pocketmine_module_entry;
#define phpext_pocketmine_ptr &pocketmine_module_entry

#endif
