
namespace PocketMine\Utils;

class Random{
	
	protected z = 0;
	protected w = 0;
	
	public function __construct(int seed){
		this->setSeed(seed);
	}
	
	public function setSeed(int seed) -> void{
		let this->z = seed ^ 0xdeadbeef;
		let this->w = seed ^ 0xc0de1337;
	}
	
	/**
	 * Returns an 31-bit integer (not signed)
	 */
	public function nextInt() -> int{
		return this->nextSignedInt() & 0x7fffffff;
	}
	
	/**
	 * Returns an 32-bit integer (signed)
	 */
	public function nextSignedInt() -> int{
		let this->z = 36969 * (this->z & 65535) + (this->z * 65536);
		let this->w = 18000 * (this->w & 65535) + (this->w * 65536);
		return this->z * 65536 + this->w;
	}
	
	public function nextFloat() -> float{
		return this->nextInt() / 2147483647.0;
	}
	
	public function nextSignedFloat() -> float{
		return this->nextSignedInt() / 2147483647.0;
	}
	
	public function nextBoolean() -> boolean{
		return this->nextSignedInt() >= 0;
	}
	
	public function nextRange(int start = 0, int end = 0x7fffffff) -> int{
		return start + (this->nextInt() % (end + 1 - start));
	}

}