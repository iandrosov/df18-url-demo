//
//  HelpViewController.swift
//  demourl
//
//  Created by Igor Androsov on 9/10/18.
//  Copyright © 2018 Salesforce. All rights reserved.
//

import UIKit
import ServiceCore
import ServiceChat
import ServiceCases
import ServiceKnowledge

class HelpViewController: UIViewController, SCServiceCloudDelegate {

    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Service Request"
        
        // Create configuration object with your community URL
        //let config = SCSServiceConfiguration(community: URL(string: "https://mycommunity.example.com")!)
        
        // Create configuration object with init params
        let config = SCSServiceConfiguration(
            community: URL(string: "https://df18-mobile-demo-developer-edition.na57.force.com/safedreamin")!,
            dataCategoryGroup: "Regions",
            rootDataCategory: "All")
        
        // Perform any additional configuration here
        ServiceCloud.shared().cases.caseCreateActionName = "NewCase"
        // Pass configuration to shared instance
        ServiceCloud.shared().serviceConfiguration = config
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func startChat(_ sender: Any) {
        let config = SCSChatConfiguration(liveAgentPod: "d.la1-c1-iad.salesforceliveagent.com/chat/rest",
                                          orgId: "00D0b000000uKcn",
                                          deploymentId: "5720b0000008zfr",
                                          buttonId: "liveagent_button_online_5730b00000090Fh")
        
        // Start the session
        ServiceCloud.shared().chat.startSession(with: config)        
    }
    
    @IBAction func openCase(_ sender: Any) {
        ServiceCloud.shared().cases.setInterfaceVisible(true,
                                                        animated: true,
                                                        completion: nil)
    }
    
    @IBAction func knowledgeBase(_ sender: Any) {
        ServiceCloud.shared().knowledge.setInterfaceVisible(true,
                                                            animated: true,
                                                            completion: nil)
    }
    
    
    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
