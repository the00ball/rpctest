namespace cpp rpctest.thrift
namespace py rpctest.thrift

service CalcController
{
	i32 Sum(1:i32 a, 2:i32 b),
}
