namespace PocketMine\Utils;

class Binary{
	const BIG_ENDIAN = 0x00;
	const LITTLE_ENDIAN = 0x01;
	
	public static function readTriad(string str) -> long{
		return (long) unpack("N", "\x00" . str)[1];
	}
	
	public static function writeTriad(long value) -> string{
		return substr(pack("N", value), 1);
	}
	
	public static function writeMetadata(array data) -> string{
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
	
	public static function readMetadata(string value, boolean types = true) -> array{
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
	
	public static function readBool(string b) -> boolean{
		return b[0] === 0 ? false : true;
	}
	
	public static function writeBool(boolean b){
		if(b === true){
			return "\x01";
		}else{
			return "\x00";
		}
	}
	
	public static function readByte(string c, boolean isSigned = true) -> int{
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
	
	public static function readShort(string str, boolean isSigned = true) -> int{
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
	
	public static function readLShort(string str, boolean isSigned = true){
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

	public static function readInt(string str) -> long{
		long unpacked;
		let unpacked = (long) unpack("N", str)[1];
		
		if(unpacked > 2147483647){
			let unpacked -= 4294967296;
		}
		
		return unpacked;
	}
	
	public static function writeInt(long value) -> string{
		return pack("N", value);
	}

	public static function readLInt(string str) -> long{
		long unpacked;
		let unpacked = (long) unpack("V", str)[1];
		
		if(unpacked > 2147483647){
			let unpacked -= 4294967296;
		}
		
		return unpacked;
	}
	
	public static function writeLInt(long value) -> string{
		return pack("V", value);
	}
	
	public static function readFloat(string str){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return unpack("f", str)[1];
		}else{
			return unpack("f", str->rev())[1];
		}
	}
	
	public static function writeFloat(float value){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return pack("f", value);
		}else{
			return pack("f", value)->rev();
		}
	}
	
	public static function readLFloat(string str){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return unpack("f", str->rev())[1];
		}else{
			return unpack("f", str)[1];
		}
	}
	
	public static function writeLFloat(float value){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return pack("f", value)->rev();
		}else{
			return pack("f", value);
		}
	}
	
	public static function printFloat(float value){
		return preg_replace("/(\\.\\d+?)0+$/", "$1", sprintf("%F", value));
	}
	
	public static function readDouble(string str){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return unpack("d", str)[1];
		}else{
			return unpack("d", str->rev())[1];
		}
	}
	
	public static function writeDouble(double value){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return pack("d", value);
		}else{
			return pack("d", value)->rev();
		}
	}
	
	public static function readLDouble(string str){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return unpack("d", str->rev())[1];
		}else{
			return unpack("d", str)[1];
		}
	}
	
	public static function writeLDouble(double value){
		if unlikely ENDIANNESS === self::BIG_ENDIAN{
			return pack("d", value)->rev();
		}else{
			return pack("d", value);
		}
	}
	
	private static function __s_not(string s) -> string{
		int i = 0;
		string r = "";
		while(i < s->length()){
			let r .= chr(-1 - ord(s[i]));
		}
		return r;
	}

	public static function readLong(string x, boolean isSigned = true){
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
	
	public static function readLLong(string str){
		return self::readLong(str->rev());
	}
	
	public static function writeLLong(string value){
		return self::writeLong(value)->rev();
	}
}

