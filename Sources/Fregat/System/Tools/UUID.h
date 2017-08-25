//---------------------------------------------
// UUID Generator (based on https://github.com/Bakkah/UUID/blob/master/uuid.hpp)
// Created by Volodymyr KUKSYNOK 
// 2017
//---------------------------------------------
#pragma once
#include <array>
#include <string>
//#include <cinttypes>
#include <random>
//#include <type_traits>
#include <chrono>

namespace Fregat
{
	namespace System
	{
		namespace Tools
		{
			class UUID
			{
			public:
				typedef std::array<int, 16> Bytes;
	
			private:
				UUID::Bytes bytes_;
				std::string chars_lower;
				//static constexpr const char *chars_upper = "0123456789ABCDEF";
			public:
				explicit UUID(const UUID::Bytes &bytes) :
					bytes_(bytes),
					chars_lower("0123456789abcdef")
				{
				}

				static UUID random() 
				{
					static std::mt19937 random_engine(
						std::chrono::high_resolution_clock::now().time_since_epoch().count());
					std::uniform_int_distribution<int> bits(0, 255);
					UUID::Bytes bytes;
					for (size_t i = 0; i < 16; ++i) 
					{
						bytes[i] = bits(random_engine);
					}	

					bytes[6] &= 0x0F; // clear version
					bytes[6] |= 0x40; // set version 4
						
					bytes[8] &= 0x3F; // clear variant
					bytes[8] |= 0x80; // set variant current
	
					return UUID(bytes);
				}
	
				std::string string()
				{
					std::string str("00000000-0000-0000-0000-000000000000");
					int string_indexes[] = { 0, 2, 4, 6, 9, 11, 14, 16, 19, 21,
							24, 26, 28, 30, 32, 34 };
					auto hex_chars = chars_lower.data();
					for (size_t i = 0; i < 16; ++i) {
						auto string_index = string_indexes[i];
						int dec = bytes_[i];
						str[string_index] = hex_chars[(dec >> 4) & (0xF)];
						str[string_index + 1] = hex_chars[(dec & 0xF)];
					}
					return str;
				}
				
				bool compare(const UUID &other) const 
				{
					for (size_t i = 0; i < 16; ++i) 
					{
						if (bytes_[i] != other.bytes_[i])
							return false;
					}
					return true;
				}
			};
		}
	}
}