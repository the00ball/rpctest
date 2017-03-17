import glob
import sys
sys.path.append('gen-py')
sys.path.insert(0, glob.glob('/home/sirineo/Documentos/thrift-0.10.0/lib/py/build/lib*')[0])

from rpctest.thrift import CalcController

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer


class CalcHandler:
    def __init__(self):
        self.log = {}

    def Sum(self, a, b):
        print('add(%d,%d)' % (a, b))
        return a + b

if __name__ == '__main__':
    handler = CalcHandler()
    processor = CalcController.Processor(handler)
    transport = TSocket.TServerSocket(port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)

    # You could do one of these for a multithreaded server
    # server = TServer.TThreadedServer(
    #     processor, transport, tfactory, pfactory)
    # server = TServer.TThreadPoolServer(
    #     processor, transport, tfactory, pfactory)

    print('Starting the server...')
    server.serve()
    print('done.')
