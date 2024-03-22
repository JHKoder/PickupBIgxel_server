package github.jhkoder.rest.system;

public class ProcessAccessorLinux implements ProcessAccessor {

    public native boolean isProcessRunning(String name,String extension);
    public native String getTargetProfile(String name,String extension);

    static {
        System.load(System.getProperty("user.dir")+ "/src/main/native/so/ProcessCheckLinux.so"); // 라이브러리 로드
    }
}
