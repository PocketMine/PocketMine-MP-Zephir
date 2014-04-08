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

class AxisAlignedBB{
	public minX;
	public minY;
	public minZ;
	public maxX;
	public maxY;
	public maxZ;

	public function __construct(static double minX, static double minY, static double minZ, static double maxX, static double maxY, static double maxZ){
		let this->minX = minX;
		let this->minY = minY;
		let this->minZ = minZ;
		let this->maxX = maxX;
		let this->maxY = maxY;
		let this->maxZ = maxZ;
	}

	public function setBounds(static double minX, static double minY, static double minZ, static double maxX, static double maxY, static double maxZ) -> <AxisAlignedBB>{
		let this->minX = minX;
		let this->minY = minY;
		let this->minZ = minZ;
		let this->maxX = maxX;
		let this->maxY = maxY;
		let this->maxZ = maxZ;

		return this;
	}

	public function addCoord(static double x, static double y, static double z) -> <AxisAlignedBB>{
		var vec;
		let vec = <AxisAlignedBB> clone this;
	
		if(x < 0){
			let vec->minX += x;
		}else{
			if(x > 0){
				let vec->maxX += x;
			}
		}

		if(y < 0){
			let vec->minY += y;
		}else{
			if(y > 0){
				let vec->maxY += y;
			}
		}

		if(z < 0){
			let vec->minZ += z;
		}else{
			if(z > 0){
				let vec->maxZ += z;
			}
		}

		return vec;
	}

	public function expand(static double x, static double y, static double z) -> <AxisAlignedBB>{
		var vec;
		let vec = <AxisAlignedBB> clone this;
		let vec->minX -= x;
		let vec->minY -= y;
		let vec->minZ -= z;
		let vec->maxX += x;
		let vec->maxY += y;
		let vec->maxZ += z;

		return vec;
	}

	public function offset(static double x, static double y, static double z) -> <AxisAlignedBB>{
		var vec;
		let vec = <AxisAlignedBB> clone this;
		let vec->minX += x;
		let vec->minY += y;
		let vec->minZ += z;
		let vec->maxX += x;
		let vec->maxY += y;
		let vec->maxZ += z;

		return vec;
	}

	public function contract(static double x, static double y, static double z) -> <AxisAlignedBB>{
		var vec;
		let vec = <AxisAlignedBB> clone this;
		let vec->minX += x;
		let vec->minY += y;
		let vec->minZ += z;
		let vec->maxX -= x;
		let vec->maxY -= y;
		let vec->maxZ -= z;

		return vec;
	}

	public function setBB(<AxisAlignedBB> bb) -> <AxisAlignedBB>{
		return new AxisAlignedBB(
			(double) min(this->minX, bb->minX),
			(double) min(this->minY, bb->minY),
			(double) min(this->minZ, bb->minZ),
			(double) max(this->maxX, bb->maxX),
			(double) max(this->maxY, bb->maxY),
			(double) max(this->maxZ, bb->maxZ)
		);
	}

	public function getOffsetBoundingBox(static double x, static double y, static double z) -> <AxisAlignedBB>{
		return new AxisAlignedBB(this->minX + x, this->minY + y, this->minZ + z, this->maxX + x, this->maxY + y, this->maxZ + z);
	}

	public function calculateXOffset(<AxisAlignedBB> bb, double x) -> double{
		double x1;
		double x2;
		
		if(bb->maxY <= this->minY || bb->minY >= this->maxY){
			return x;
		}
		if(bb->maxZ <= this->minZ || bb->minZ >= this->maxZ){
			return x;
		}
		if(x > 0 && bb->maxX <= this->minX){
			let x1 = this->minX - bb->maxX;
			if(x1 < x){
				let x = x1;
			}
		}
		if(x < 0 && bb->minX >= this->maxX){
			let x2 = this->maxX - bb->minX;
			if(x2 > x){
				let x = x2;
			}
		}

		return x;
	}

	public function calculateYOffset(<AxisAlignedBB> bb, double y) -> double{
		double y1;
		double y2;
	
		if(bb->maxX <= this->minX || bb->minX >= this->maxX){
			return y;
		}
		if(bb->maxZ <= this->minZ || bb->minZ >= this->maxZ){
			return y;
		}
		if(y > 0 && bb->maxY <= this->minY){
			let y1 = this->minY - bb->maxY;
			if(y1 < y){
				let y = y1;
			}
		}
		if(y < 0 && bb->minY >= this->maxY){
			let y2 = this->maxY - bb->minY;
			if(y2 > y){
				let y = y2;
			}
		}

		return y;
	}

	public function calculateZOffset(<AxisAlignedBB> bb, double z) -> double{
		double z1;
		double z2;
	
		if(bb->maxX <= this->minX || bb->minX >= this->maxX){
			return z;
		}
		if(bb->maxY <= this->minY || bb->minY >= this->maxY){
			return z;
		}
		if(z > 0 && bb->maxZ <= this->minZ){
			let z1 = this->minZ - bb->maxZ;
			if(z1 < z){
				let z = z1;
			}
		}
		if(z < 0 && bb->minZ >= this->maxZ){
			let z2 = this->maxZ - bb->minZ;
			if(z2 > z){
				let z = z2;
			}
		}

		return z;
	}

	public function intersectsWith(<AxisAlignedBB> bb) -> boolean{
		if(bb->maxX <= this->minX || bb->minX >= this->maxX){
			return false;
		}
		if(bb->maxY <= this->minY || bb->minY >= this->maxY){
			return false;
		}

		return bb->maxZ > this->minZ && bb->minZ < this->maxZ;
	}

	public function isVectorInside(<Vector3> vector) -> boolean{
		if(vector->x <= this->minX || vector->x >= this->maxX){
			return false;
		}
		if(vector->y <= this->minY || vector->y >= this->maxY){
			return false;
		}

		return vector->z > this->minZ && vector->z < this->maxZ;
	}

	public function getAverageEdgeLength() -> double{
		return (this->maxX - this->minX + this->maxY - this->minY + this->maxZ - this->minZ) / 3;
	}

	public function isVectorInYZ(<Vector3> vector) -> boolean{
		return vector->y >= this->minY && vector->y <= this->maxY && vector->z >= this->minZ && vector->z <= this->maxZ;
	}
s
	public function isVectorInXZ(<Vector3> vector) -> boolean{
		return vector->x >= this->minX && vector->x <= this->maxX && vector->z >= this->minZ && vector->z <= this->maxZ;
	}

	public function isVectorInXY(<Vector3> vector) -> boolean{
		return vector->x >= this->minX && vector->x <= this->maxX && vector->y >= this->minY && vector->y <= this->maxY;
	}
}