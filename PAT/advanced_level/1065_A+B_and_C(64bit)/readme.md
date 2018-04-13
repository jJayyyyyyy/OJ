```cpp
if( a>0 && b>0 && sum<0 ){
	// sum<0 means overflow
	// a + b > 2^63 >= c
	cout<<"Case #"<<i<<": true\n";
}else if( a<0 && b<0 && sum>=0 ){
	// sum>=0 means overflow
	// a + b < -2^63 <= c
	cout<<"Case #"<<i<<": false\n";
}else if( sum > c ){
	cout<<"Case #"<<i<<": true\n";
}else{
	cout<<"Case #"<<i<<": false\n";
}
```