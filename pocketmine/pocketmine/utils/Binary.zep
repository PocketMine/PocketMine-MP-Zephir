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

class Binary{
	const BIG_ENDIAN = 0x00;
	const LITTLE_ENDIAN = 0x01;
	
	public static function readTriad(const string str) -> long{
		return (long) unpack("N", "\x00" . str)[1];
	}
	
	public static function writeTriad(const long value) -> string{
		return substr(pack("N", value), 1);
	}
	
	public static function writeMetadata(const array data) -> string{
		string m = "";
		
		var bottom;
		var d;		
		for bottom, d in data {
			let m .= chr((d[0] * 32) + (bottom & 0x1f));
			switch d[0]{
				case 0:
					let m .= self::writeByte(d[1]);
					break;
				case 1:
					let m .= self::writeLShort(d[1]);
					break;
				case 2:
					let m .= self::writeLInt(d[1]);
					break;
				case 3:
					let m .= self::writeLFloat(d[1]);
					break;
				case 4:
					let m .= self::writeLShort(d[1]) . d[1];
					break;
				case 5:
					let m .= self::writeLShort(d[1][0]);
					let m .= self::writeByte(d[1][1]);
					let m .= self::writeLShort(d[1][2]);
					break;
				case 6:
					let m .= self::writeLInt(d[1][0]);
					let m .= self::writeLInt(d[1][1]);
					let m .= self::writeLInt(d[1][2]);
					break;
			}
		}
		
		return m . "\x7f";
	}
	
	public static function readMetadata(const string value, const boolean types = true) -> array{
		long offset = 1;
		array m = [];
		uchar b;
		int bottom;
		int type;
		var r;
		var len;
		
		let b = value[0];
		
		while b !== 127 && value[offset] !== 0 {
			let bottom = b & 0x1f;
			let type = (b & 0xe0) / 32;
			switch type {
				case 0:
					let r = self::readByte(ord(value[offset]));
					let offset++;
					break;
				case 1:
					let r = self::readLShort(substr(value, offset, 2));
					let offset += 2;
					break;
				case 2:
					let r = self::readLInt(substr(value, offset, 4));
					let offset += 4;
					break;
				case 3:
					let r = self::readLFloat(substr(value, offset, 4));
					let offset += 4;
					break;
				case 4:
					let len = self::readLShort(substr(value, offset, 2));
					let offset += 2;
					let r = substr(value, offset, len);
					let offset += len;
					break;
				case 5:
					let r = [];
					let r[] = self::readLShort(substr(value, offset, 2));
					let offset += 2;
					let r[] = ord(value[offset]);
					let offset++;
					let r[] = self::readLShort(substr(value, offset, 2));
					let offset += 2;
					break;
				case 6:
					let r = [];
					let r[] = self::readLInt(substr(value, offset, 4));
					let offset += 4;
					let r[] = self::readLInt(substr(value, offset, 4));
					let offset += 4;
					let r[] = self::readLInt(substr(value, offset, 4));
					let offset += 4;
					break;
			}
			
			if(types === true){
				let m[bottom] = [r, type];
			}else{
				let m[bottom] = r;
			}
			let b = value[offset];
			let offset++;
		}
		
		return m;
	}
	
	public static function readBool(const string b) -> boolean{
		return b[0] === 0 ? false : true;
	}
	
	public static function writeBool(const boolean b){
		if(b === true){
			return "\x01";
		}else{
			return "\x00";
		}
	}
	
	public static function readByte(const string c, const boolean isSigned = true) -> int{
		int b;
		let b = ord(c[0]) * (int) 1;
		if(isSigned === true && (b & 0x80) > 0){
			let b = -0x80 + (b & 0x7f);
		}
		
		return b;
	}
	
	public static function writeByte(int c) -> string{
		if(c < 0 && c >= -0x80){
			let c = 0xff + c + 1;
		}
		
		return chr(c);
	}
	
	public static function readShort(const string str, const boolean isSigned = true) -> int{
		int unpacked;
		let unpacked = (int) unpack("n", str)[1];
		
		if(unpacked > 0x7fff && isSigned === true){
			let unpacked -= 0x10000;
		}
		
		return unpacked;
	}
	
	public static function writeShort(long value) -> string{
		if(value < 0){
			let value += 0x10000;
		}
		return pack("n", value);
	}
	
	public static function readLShort(const string str, const boolean isSigned = true){
		int unpacked;
		let unpacked = (int) unpack("v", str)[1];
		
		if(unpacked > 0x7fff && isSigned === true){
			let unpacked -= 0x10000;
		}
		
		return unpacked;
	}
	
	public static function writeLShort(long value) -> string{
		if(value < 0){
			let value += 0x10000;
		}
		return pack("v", value);
	}

	public static function readInt(const string str) -> long{
		long unpacked;
		let unpacked = (long) unpack("N", str)[1];
		
		if(unpacked > 2147483647){
			let unpacked -= 4294967296;
		}
		
		return unpacked;
	}
	
	public static function writeInt(const long value) -> string{
		return pack("N", value);
	}

	public static function readLInt(const string str) -> long{
		long unpacked;
		let unpacked = (long) unpack("V", str)[1];
		
		if(unpacked > 2147483647){
			let unpacked -= 4294967296;
		}
		
		return unpacked;
	}
	
	public static function writeLInt(const long value) -> string{
		return pack("V", value);
	}
	
	public static function readFloat(const string str){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return unpack("f", str)[1];
		}else{
			return unpack("f", str->rev())[1];
		}
	}
	
	public static function writeFloat(const float value){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return pack("f", value);
		}else{
			return strrev(pack("f", value));
		}
	}
	
	public static function readLFloat(const string str){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return unpack("f", str->rev())[1];
		}else{
			return unpack("f", str)[1];
		}
	}
	
	public static function writeLFloat(const float value){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return strrev(pack("f", value));
		}else{
			return pack("f", value);
		}
	}
	
	public static function printFloat(const float value){
		return preg_replace("/(\\.\\d+?)0+$/", "$1", sprintf("%F", value));
	}
	
	public static function readDouble(const string str){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return unpack("d", str)[1];
		}else{
			return unpack("d", str->rev())[1];
		}
	}
	
	public static function writeDouble(const double value){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return pack("d", value);
		}else{
			return strrev(pack("d", value));
		}
	}
	
	public static function readLDouble(const string str){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return unpack("d", str->rev())[1];
		}else{
			return unpack("d", str)[1];
		}
	}
	
	public static function writeLDouble(const double value){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return strrev(pack("d", value));
		}else{
			return pack("d", value);
		}
	}

	public static function readLong(const string x, const boolean isSigned = true){
		var value = "0";
		int i = 0;
		
		while i < 8 {
			let value = bcmul(value, "65536", 0);
			let value = bcadd(value, Binary::readShort(substr(x, i, 2), false), 0);
			let i += 2;
		}
		
		if(isSigned === true && bccomp(value, "9223372036854775807") == 1){
			let value = bcadd(value, "-18446744073709551616");
		}
		
		return value;
	}
	
	public static function writeLong(var value){
		string x = "";
		
		if(bccomp(value, "0") == -1){
			let value = bcadd(value, "18446744073709551616");
		}

		let x .= self::writeShort(bcmod(bcdiv(value, "281474976710656"), "65536"));
		let x .= self::writeShort(bcmod(bcdiv(value, "4294967296"), "65536"));
		let x .= self::writeShort(bcmod(bcdiv(value, "65536"), "65536"));
		let x .= self::writeShort(bcmod(value, "65536"));
		
		return x;
	}
	
	public static function readLLong(const string str){
		return self::readLong(str->rev());
	}
	
	public static function writeLLong(const string value){
		return strrev(self::writeLong(value));
	}
}

