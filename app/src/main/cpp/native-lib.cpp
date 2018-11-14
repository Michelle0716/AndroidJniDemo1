#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_example_centerm_jnidemo_JniUtil_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}



extern "C"
JNIEXPORT jint JNICALL
Java_com_example_centerm_jnidemo_JniUtil_intFromJNI(JNIEnv *env, jobject instance) {
//返回int
    int rtn=5;
    return (jint) rtn ;
}


extern "C"
JNIEXPORT jintArray JNICALL
Java_com_example_centerm_jnidemo_JniUtil_getArray(JNIEnv *env, jobject instance,
                                                       jintArray arr_) {
   //返回整形数组
    jboolean f= false;
    jint *elems = env->GetIntArrayElements(arr_,&f);
    int len = env->GetArrayLength(arr_);

    for (int i = 0; i < len; i++){
        elems[i] = elems[i]*3;
    }
    jintArray jint_arr = env->NewIntArray( len);
    env->ReleaseIntArrayElements( jint_arr, elems,1);
    return jint_arr;


}extern "C"
JNIEXPORT jdouble JNICALL
Java_com_example_centerm_jnidemo_JniUtil_getDouble(JNIEnv *env, jobject instance, jdouble d) {

    // TODO返回duble
    return d*2;

}