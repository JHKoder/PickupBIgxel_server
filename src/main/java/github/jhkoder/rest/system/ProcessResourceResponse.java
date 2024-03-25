package github.jhkoder.rest.system;

import java.time.LocalDateTime;

public class ProcessResourceResponse {

    private LocalDateTime startTime;

    private double cpuUsage;
    private double memoryUsage;

    // 생성자
    public ProcessResourceResponse(LocalDateTime startTime, double cpuUsage, double memoryUsage) {
        this.startTime = startTime;
        this.cpuUsage = cpuUsage;
        this.memoryUsage = memoryUsage;
    }

    // Getter 메서드
    public LocalDateTime getStartTime() {
        return startTime;
    }

    public double getCpuUsage() {
        return cpuUsage;
    }

    public double getMemoryUsage() {
        return memoryUsage;
    }
}
