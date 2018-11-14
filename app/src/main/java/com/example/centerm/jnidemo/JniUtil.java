package com.example.centerm.jnidemo;

/**
 * Created by centerm on 2018/11/13.
 */

public class JniUtil {


    public JniUtil() {
        super();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */

    static {
        System.loadLibrary("native-lib");
    }


    public native String stringFromJNI();
    public native int  intFromJNI();
    public native  int[]  getArray(int[] arr);
    public native  double  getDouble(double d);

}
