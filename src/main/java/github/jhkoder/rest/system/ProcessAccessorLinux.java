package github.jhkoder.rest.system;

import java.nio.file.Path;

public class ProcessAccessorLinux implements ProcessAccessor {

    public native boolean isProcessRunning(String name,String extension);
    public native ProcessResourceResponse getTargetProfile(String name,String extension);

    static {
        String path = Path.of(System.getProperty("user.dir"),
                "src","main","native","so","ProcessCheckLinux.so").toString();
        System.load(path);
    }
}
