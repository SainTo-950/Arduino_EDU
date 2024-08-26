package com.ioteducation.iotedu.web.iotDashboard;

import java.util.HashMap;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class IoTDataCheckService {
    @Autowired
    private IoTDataCheckDAO ioTDataCheckDAO;

    public int insertGatheringData(Map<String, Object> vo) {
        int rtnVal = ioTDataCheckDAO.insertGatheringData(vo);

        return rtnVal;
    }

    public Map<String, Object> getLastData(String dvcId) {
        Map<String, Object> vo = new HashMap<>();
        vo.put("dvc_id", dvcId);

        return ioTDataCheckDAO.getLastData(vo);
    }
}
