package com.example.watermyplant.Rest;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.time.LocalDateTime;

@RestController
@RequestMapping("/api")
public class MyRestController {

    @GetMapping("/test")
    public String helloWorld(){
        return "Hello World, it's : " + LocalDateTime.now();
    }

}
