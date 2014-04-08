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

namespace PocketMine\Math;

class Vector2{
	public x;
	public y;
	
	public function __construct(var x = 0, var y = 0){
		let this->x = x;
		let this->y = y;
	}
	
	public function getX(){
		return this->x;
	}
	
	public function getY(){
		return this->y;
	}
	
	public function getFloorX() -> long{
		return (long) this->x;
	}
	
	public function getFloorY() -> long{
		return (long) this->y;
	}
	
	public function add(var x = 0, var y = 0) -> <Vector2>{
		if(x instanceof Vector2){
			return <Vector2> this->add(x->x, x->y);
		}else{
			return new Vector2(this->x + x, this->y + y);
		}
	}
	
	public function subtract(var x, var y = 0) -> <Vector2>{
		if(x instanceof Vector2){
			return <Vector2> this->add(-x->x, -x->y);
		}else{
			return <Vector2> this->add(-x, -y);
		}
	}
	
	public function ceil() -> <Vector2>{
		return new Vector2((long) (this->x + 1), (long) (this->y + 1));
	}
	
	public function floor() -> <Vector2>{
		return new Vector2((long) this->x, (long) this->y);
	}
	
	public function round() -> <Vector2>{
		return new Vector2((long) round(this->x), (long) round(this->y));
	}
	
	public function abs() -> <Vector2>{
		return new Vector2(abs(this->x), abs(this->y));
	}
	
	public function multiply(var number) -> <Vector2>{
		return new Vector2(this->x * number, this->y * number);
	}
	
	public function divide(var number) -> <Vector2>{
		return new Vector2(this->x / number, this->y / number);
	}
	
	public function distance(var x, var y = 0) -> double{
		if(x instanceof Vector2){
			return (double) sqrt(this->distanceSquared(x->x, x->y));
		}else{
			return (double) sqrt(this->distanceSquared(x, y));
		}
	}
	
	public function distanceSquared(var x, var y = 0) -> double{
		if(x instanceof Vector2){
			return (double) this->distanceSquared(x->x, x->y);
		}else{
			return (double) (pow(this->x - x, 2) + pow(this->y - y, 2));
		}
	}
	
	public function length() -> double{
		return (double) sqrt(this->lengthSquared());
	}
	
	public function lengthSquared() -> double{
		return (double) (this->x * this->x + this->y * this->y);
	}
	
	public function normalize() -> <Vector2>{
		double len;
		let len = this->length();
		if(len != 0){
			return <Vector2> this->divide(len);
		}
		
		return new Vector2(0, 0);
	}
	
	public function dot(<Vector2> v) -> double{
		return (double) (this->x * v->x + this->y * v->y);
	}
	
	public function __toString() -> string{
		return "Vector2(x=" . (string) this->x . ",y=". (string) this->y . ")";
	}
	
}