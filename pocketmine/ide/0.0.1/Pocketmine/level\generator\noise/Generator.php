<?php

namespace PocketMine\Level\Generator\Noise;

abstract class Generator
{
	protected $perm = array();
	protected $offsetX = 0;
	protected $offsetY = 0;
	protected $offsetZ = 0;
	protected $octaves = 8;
	protected $frequency;
	protected $amplitude;

	public static function floor()    {
    }

	public static function fade()    {
    }

	public static function lerp()    {
    }

	public static function grad()    {
    }

	abstract public function getNoise2D();

	abstract public function getNoise3D();

	public function noise2D()    {
    }

	public function noise3D()    {
    }

	public function setOffset()    {
    }

	public function __construct()    {
    }

}
