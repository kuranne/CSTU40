package func.io;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;

public class FastReader {
    private final int BUF_SIZE = 1 << 16;
    private final DataInputStream din;
    private final byte[] buf;
    private int bufPointer, bytesRead;

    public FastReader(InputStream in) {
        din = new DataInputStream(in);
        buf = new byte[BUF_SIZE];
        bufPointer = bytesRead = 0;
    }

    public long nextLong() {
        long ret = 0;
        boolean neg;
        try {
            byte c = read();
            while (c <= ' ') c = read();
            if (neg = (c == '-')) c = read();
            do { 
                ret = ret * 10 + (c - '0');
            } while ((c = read()) >= '0' && c <= '9');
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        return (neg) ? -ret : ret;
    }

    private byte read() throws IOException {
        if (bufPointer == bytesRead) fillBuf();
        return buf[bufPointer++];
    }

    private void fillBuf() throws IOException {
        bytesRead = din.read(buf, bufPointer = 0, BUF_SIZE);
        if (bytesRead == 0) buf[0] = -1;
    }
}
