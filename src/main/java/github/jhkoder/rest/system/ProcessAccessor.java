package github.jhkoder.rest.system;

public interface ProcessAccessor {

    boolean isProcessRunning(String name, String extension);

    ProcessResourceResponse getTargetProfile(String name, String extension);
}
