package github.jhkoder.rest.system;


import java.nio.file.Path;

public class ProcessAccessorWindows implements ProcessAccessor {


    public native boolean isProcessRunning(String name, String extension);

    public native String getTargetProfile(String name, String extension);

    static {
        String path = Path.of(System.getProperty("user.dir"),
                        "src","main","native","dll","ProcessCheckWindows.dll")
                        .toString();
        System.out.println(path);
        System.load(path);
    }

}
