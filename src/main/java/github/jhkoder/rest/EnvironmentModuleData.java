package github.jhkoder.rest;


import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.PropertySource;
import org.springframework.stereotype.Component;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

@Component
@ConfigurationProperties(prefix = "environment")
@PropertySource(value = "classpath:environment-modules.yml", factory = EnvironmentModuleConfigFactory.class)
public class EnvironmentModuleData {
    private List<EnvironmentModuleDataRequest> modules;

    public List<EnvironmentModuleDataRequest> getModules() {
        return modules;
    }

    public void setModules(Map<String, String> modules) {
        this.modules = new ArrayList<>();
        for (Map.Entry<String, String> entry : modules.entrySet()) {
            String moduleName = entry.getKey();
            String jarName = entry.getValue();
            EnvironmentModuleDataRequest request = new EnvironmentModuleDataRequest(moduleName, jarName);
            this.modules.add(request);
        }
    }

    public EnvironmentModuleData(List<EnvironmentModuleDataRequest> modules) {
        this.modules = modules;
    }
}
