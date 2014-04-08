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

class Vector3{
	public x;
	public y;
	public z;
	
	public function __construct(var x = 0, var y = 0, var z = 0){
		let this->x = x;
		let this->y = y;
		let this->z = z;
	}
	
	public function getX(){
		return this->x;
	}
	
	public function getY(){
		return this->y;
	}
	
	public function getZ(){
		return this->z;
	}
	
	public function getFloorX() -> long{
		return (long) this->x;
	}
	
	public function getFloorY() -> long{
		return (long) this->y;
	}
	
	public function getFloorZ() -> long{
		return (long) this->z;
	}
	
	public function getRight(){
		return this->x;
	}
	
	public function getUp(){
		return this->y;
	}
	
	public function getForward(){
		return this->z;
	}
	
	public function getSouth(){
		return this->x;
	}
	
	public function getWest(){
		return this->z;
	}
	
	public function add(var, var y = 0, var z = 0) -> <Vector3>{
		if(x instanceof Vector3){
			return <Vector3> this->add(x->x, x->y, x->z);
		}else{
			return new Vector3(this->x + x, this->y + y, this->z + z);
		}
	}
	
	public function subtract(var x, var y = 0) -> <Vector3>{
		if(x instanceof Vector3){
			return <Vector3> this->add(-x->x, -x->y, -x->z);
		}else{
			return <Vector3> this->add(-x, -y, -z);
		}
	}
	
	public function ceil() -> <Vector3>{
		return new Vector3((long) (this->x + 1), (long) (this->y + 1), (long) (this->z + 1));
	}
	
	public function floor() -> <Vector3>{
		return new Vector3((long) this->x, (long) this->y, (long) this->z);
	}
	
	public function round() -> <Vector3>{
		return new Vector3((long) round(this->x), (long) round(this->y), (long) round(this->z));
	}
	
	public function abs() -> <Vector3>{
		return new Vector3(abs(this->x), abs(this->y), abs(this->z));
	}
	
	public function multiply(var number) -> <Vector3>{
		return new Vector3(this->x * number, this->y * number, this->z * number);
	}
	
	public function divide(var number) -> <Vector3>{
		return new Vector3(this->x / number, this->y / number, this->z / number);
	}

	public function getSide(int side, int step = 1) -> <Vector3>{
		switch side{
			case 0:
				return new Vector3(this->x, this->y - step, this->z);
			case 1:
				return new Vector3(this->x, this->y + step, this->z);
			case 2:
				return new Vector3(this->x, this->y, this->z - step);
			case 3:
				return new Vector3(this->x, this->y, this->z + step);
			case 4:
				return new Vector3(this->x - step, this->y, this->z);
			case 5:
				return new Vector3(this->x + step, this->y, this->z);
		}
		
		return this;
	}
	
	public function distance(<Vector3> pos) -> double{
		return (double) sqrt(this->distanceSquared(pos));
	}
	
	public function distanceSquared(<Vector3> pos) -> double{
		return (double) (pow(this->x - pos->x, 2) + pow(this->y - pos->y, 2) + pow(this->z - pos->z, 2));
	}
	
	public function maxPlainDistance(var x, var z) -> double{
		if(x instanceof Vector3){
			return (double) this->maxPlainDistance(x->x, x->z);
		}elseif(x instanceof Vector2){
			return (double) this->maxPlainDistance(x->x, x->y);
		}else{
			return (double) max(abs(this->x - x), abs(this->z - z));
		}
	}
	
	public function length() -> double{
		return (double) sqrt(this->lengthSquared());
	}
	
	public function lengthSquared() -> double{
		return (double) (this->x * this->x + this->y * this->y + this->z * this->z);
	}
	
	public function normalize() -> <Vector3>{
		double len;
		let len = this->length();
		if(len != 0){
			return <Vector3> this->divide(len);
		}
		
		return new Vector3(0, 0, 0);
	}
	
	public function dot(<Vector3> v) -> double{
		return (double) (this->x * v->x + this->y * v->y + this->z * v->z);
	}
	
	public function cross(<Vector3> v) -> <Vector3>{
		return new Vector3(
			this->y * v->z - this->z * v->y,
			this->z * v->x - this->x * v->z,
			this->x * v->y - this->y * v->x
		);
	}
	
	public function __toString() -> string{
		return "Vector3(x=" . (string) this->x . ",y=". (string) this->y . ",y=". (string) this->z . ")";
	}
	
}