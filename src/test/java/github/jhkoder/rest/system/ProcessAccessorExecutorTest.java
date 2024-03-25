package github.jhkoder.rest.system;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName("네이티브 코드 테스트")
public class ProcessAccessorExecutorTest {

    @Test
    void isProcessRunning_windows(){
        ProcessAccessorExecutor executor = new ProcessAccessorExecutor();
        Assertions.assertTrue(executor.isProcessRunning("services","exe"));
    }
}
