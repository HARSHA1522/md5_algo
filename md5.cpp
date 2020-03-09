#include <bits/stdc++.h>
using namespace std;

//function to convert binary sequence to string
string BinarytoString(string bit_stream)
{
	stringstream sstream(bit_stream);
	string output;
	while (sstream.good())
	{
		bitset<8> bits;
		sstream >> bits;
		char c = char(bits.to_ulong());
		output += c;
	}
	//correction
	output.pop_back();
	// cout << output;
	return output;
}

int main()
{
	//1. take input///////////
	//we assume that msg string is not greater than 512 bits in size
	string msg;
	getline(cin, msg);

	//2. padding//////////////
	//convert to bits
	cout << "binary sequence of msg string is: ";
	for (size_t i = 0; i < msg.size(); ++i)
	{
		//print out the bit sequence of msg string
		cout << bitset<8>(msg.c_str()[i]);
	}
	cout << endl;

	int len = msg.size();   //calculate length of message string
	int len_bits = len * 8; //length in bits (1 char = 1 byte = 8 bits)

	//calculate no of bits to be padded at the end
	int len_pad = 512 - 64 - len_bits;

	string pad_string_bit_seq = "1";
	for (int i = 0; i < len_pad-1; i++)
	{
		pad_string_bit_seq += "0";
	}

	//convert string binary seqeunce to string
	string pad_string = BinarytoString(pad_string_bit_seq);
	string msg_padded = msg + pad_string; //append the padded character sequence at the end of msg

	cout << "padded msg string is :";
	cout << msg_padded << endl;
	cout << "binary sequence of padded msg string is: ";
	// check if the string is correct by printing the bit sequence
	for (size_t i = 0; i < msg_padded.size(); ++i)
	{
		//print out the bit sequence of msg string
		cout << bitset<8>(msg_padded.c_str()[i]);
	}
	cout << endl;

	//3. add length bits////////////
	string len_pad_string = "";
	int len_temp = len * 8;
	cout << len_temp << endl;
	while (len_temp != 0)
	{
		int r = len_temp % 2;
		if (r == 1)
		{
			len_pad_string += "1";
		}
		else
			len_pad_string += "0";
		len_temp /= 2;
	}
	reverse(len_pad_string.begin(), len_pad_string.end());
	// cout<<len_pad_string<<endl;
	len_temp = 64 - len_pad_string.size();
	// cout<<len_temp<<endl;
	for (int i = 0; i < len_temp; i++)
	{
		len_pad_string = "0" + len_pad_string;
	}
	cout << "length bit" << endl;
	// cout<<len_bits<<endl;
	cout << len_pad_string << endl;

	pad_string = BinarytoString(len_pad_string);
	msg_padded += pad_string;
	cout << "final padded string: ";
	cout << msg_padded << endl;
	cout << msg_padded.size();
	for (size_t i = 0; i < msg_padded.size(); ++i)
	{
		//print out the bit sequence of msg string
		cout << bitset<8>(msg_padded.c_str()[i])<<endl;
		cout<<i+1<<endl;
	}
	cout << endl;


	//call F-block procedure

	//call G-block procedure

	//call H-block procedure

	//call I-block procedure
	//store msg digest
	return 0;
}