<?php

namespace PocketMine\Utils;

class Random
{
	protected $z = 0;
	protected $w = 0;

	/**
	 * @param int $seed Integer to be used as seed.
	 */
	public function __construct()    {
    }

	/**
	 * @param int $seed Integer to be used as seed.
	 */
	public function setSeed()    {
    }

	/**
	 * Returns an 31-bit integer (not signed)
	 *
	 * @return int
	 */
	public function nextInt()    {
    }

	/**
	 * Returns a 32-bit integer (signed)
	 *
	 * @return int
	 */
	public function nextSignedInt()    {
    }

	/**
	 * Returns a float between 0.0 and 1.0 (inclusive)
	 *
	 * @return float
	 */
	public function nextFloat()    {
    }

	/**
	 * Returns a float between -1.0 and 1.0 (inclusive)
	 *
	 * @return float
	 */
	public function nextSignedFloat()    {
    }

	/**
	 * Returns a random boolean
	 *
	 * @return bool
	 */
	public function nextBoolean()    {
    }

	/**
	 * Returns a random integer between $start and $end
	 *
	 * @param int $start default 0
	 * @param int $end   default 0x7fffffff
	 *
	 * @return int
	 */
	public function nextRange()    {
    }

}
