package github.jhkoder.rest;


import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.PropertySource;
import org.springframework.stereotype.Component;

import java.util.List;

@Component
@ConfigurationProperties(prefix = "environment")
@PropertySource(value = "classpath:environment-modules.yml", factory = EnvironmentModuleConfigFactory.class)
public class EnvironmentModuleData {
    private List<String> modules;

    public List<String> getModules() {
        return modules;
    }

    public void setModules(List<String> modules) {
        this.modules = modules;
    }
}
