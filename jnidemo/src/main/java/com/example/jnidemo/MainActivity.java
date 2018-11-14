package com.example.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import com.example.centerm.jnidemo.JniUtil;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        JniUtil jniUtil=new JniUtil();
        Log.e("测试","c数据"+jniUtil.stringFromJNI()+"\n"+jniUtil.intFromJNI());
        //
    }
}
