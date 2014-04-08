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

namespace PocketMine\Utils;

/**
 * Unsecure Random Number Generator, used for fast seeded values
 */
class Random{
	
	protected seed;

	/**
	 * @param int $seed Integer to be used as seed.
	 */
	public function __construct(long seed = -1){
		if(seed == -1){
			let seed = (long) time();
		}
		this->setSeed(seed);
	}

	/**
	 * @param int $seed Integer to be used as seed.
	 */
	public function setSeed(const long seed) -> void{
		let this->seed = (long) crc32(Binary::writeInt(seed));
	}
	
	/**
	 * Returns an 31-bit integer (not signed)
	 *
	 * @return int
	 */
	public function nextInt() -> long{
		return (long) this->nextSignedInt() & 0x7fffffff;
	}

	/**
	 * Returns a 32-bit integer (signed)
	 *
	 * @return int
	 */
	public function nextSignedInt() -> long{
		long t;
		let t = crc32(Binary::writeInt(this->seed));
		let this->seed = this->seed ^ t;

		if(t > 2147483647){
			let t -= 4294967296;
		}
		return (long) t;
	}

	/**
	 * Returns a float between 0.0 and 1.0 (inclusive)
	 *
	 * @return float
	 */
	public function nextFloat() -> float{
		return (float) this->nextInt() / 2147483647.0;
	}
	
	/**
	 * Returns a float between -1.0 and 1.0 (inclusive)
	 *
	 * @return float
	 */
	public function nextSignedFloat() -> float{
		return (float) this->nextSignedInt() / 2147483647.0;
	}
	
	/**
	 * Returns a random boolean
	 *
	 * @return bool
	 */
	public function nextBoolean() -> boolean{
		return (long) this->nextSignedInt() >= 0;
	}
	
	/**
	 * Returns a random integer between $start and $end
	 *
	 * @param int $start default 0
	 * @param int $end   default 0x7fffffff
	 *
	 * @return int
	 */
	public function nextRange(const long start = 0, const long end = 0x7fffffff) -> long{
		return start + ((long) this->nextInt() % (end + 1 - start));
	}

}