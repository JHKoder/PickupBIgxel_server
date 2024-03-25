package github.jhkoder.rest.system;

import org.springframework.stereotype.Component;

@Component
public class ProcessAccessorExecutor implements ProcessAccessor{

    private final ProcessAccessor processAccessor;

    public ProcessAccessorExecutor() {
        if (System.getProperty("os.name").toLowerCase().contains("windows")) {
            this.processAccessor = new ProcessAccessorWindows();
        } else {
            this.processAccessor = new ProcessAccessorLinux();
        }
    }

    @Override
    public boolean isProcessRunning(String name, String extension) {
        return processAccessor.isProcessRunning(name,"."+extension);
    }
    public boolean isProcessRunning(String name) {
        return processAccessor.isProcessRunning(name,"");
    }

    @Override
    public ProcessResourceResponse getTargetProfile(String name, String extension) {
        return processAccessor.getTargetProfile(name,extension);
    }
    public ProcessResourceResponse getTargetProfile(String name) {
        return processAccessor.getTargetProfile(name,"");
    }
}