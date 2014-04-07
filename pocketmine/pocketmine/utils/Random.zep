
namespace PocketMine\Utils;

/**
 * Unsecure Random Number Generator, used for fast seeded values
 */
class Random{
	
	protected z = 0;
	protected w = 0;

	/**
	 * @param int $seed Integer to be used as seed.
	 */
	public function __construct(long seed = 0){
		this->setSeed(seed);
	}

	/**
	 * @param int $seed Integer to be used as seed.
	 */
	public function setSeed(long seed) -> void{
		let this->z = seed ^ 0xdeadbeef;
		let this->w = seed ^ 0xc0de1337;
	}
	
	/**
	 * Returns an 31-bit integer (not signed)
	 *
	 * @return int
	 */
	public function nextInt() -> long{
		return this->nextSignedInt() & 0x7fffffff;
	}

	/**
	 * Returns a 32-bit integer (signed)
	 *
	 * @return int
	 */
	public function nextSignedInt() -> long{
		let this->z = 36969 * (this->z & 65535) + (this->z * 65536);
		let this->w = 18000 * (this->w & 65535) + (this->w * 65536);
		return this->z * 65536 + this->w;
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
		return this->nextSignedInt() >= 0;
	}
	
	/**
	 * Returns a random integer between $start and $end
	 *
	 * @param int $start default 0
	 * @param int $end   default 0x7fffffff
	 *
	 * @return int
	 */
	public function nextRange(long start = 0, long end = 0x7fffffff) -> long{
		return start + ((long) this->nextInt() % (end + 1 - start));
	}

}