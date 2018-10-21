//
//  DemoViewController.swift
//  demourl
//
//  Created by Igor Androsov on 9/9/18.
//  Copyright © 2018 Salesforce. All rights reserved.
//

import Foundation
import UIKit
import SalesforceSDKCore
import SalesforceSwiftSDK
import PromiseKit
class DemoViewController : UITableViewController
{
    var dataRows = [NSDictionary]()
    
    @IBAction func openHelper(_ sender: UIBarButtonItem) {
        performSegue(withIdentifier: "HelpViewSegu", sender: self)

    }
    
    // MARK: - View lifecycle
    override func loadView()
    {
        super.loadView()
        self.title = "Active Accounts"
        let restApi = SFRestAPI.sharedInstance()
        restApi.Promises
            .query(soql: "SELECT Id, Name FROM Account LIMIT 20")
            .then {  request  in
                restApi.Promises.send(request: request)
            }.done { [unowned self] response in
                self.dataRows = response.asJsonDictionary()["records"] as! [NSDictionary]
                SalesforceSwiftLogger.log(type(of:self), level:.debug, message:"request:didLoadResponse: #records: \(self.dataRows.count)")
                DispatchQueue.main.async(execute: {
                    self.tableView.reloadData()
                })
            }.catch { error in
                SalesforceSwiftLogger.log(type(of:self), level:.debug, message:"Error: \(error)")
        }
    }
    
    // MARK: - Table view data source
    func numberOfSectionsInTableView(tableView: UITableView) -> Int
    {
        return 1
    }
    
    override func tableView(_ tableView: UITableView?, numberOfRowsInSection section: Int) -> Int
    {
        return self.dataRows.count
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        let cellIdentifier = "CellIdentifier"
        
        // Dequeue or create a cell of the appropriate type.
        var cell:UITableViewCell? = tableView.dequeueReusableCell(withIdentifier:cellIdentifier)
        if (cell == nil)
        {
            cell = UITableViewCell(style: .subtitle, reuseIdentifier: cellIdentifier)
        }
        
        // If you want to add an image to your cell, here's how.
        let image = UIImage(named: "icon.png")
        cell!.imageView!.image = image
        
        // Configure the cell to show the data.
        let obj = dataRows[indexPath.row]
        cell!.textLabel!.text = obj["Name"] as? String
        cell!.detailTextLabel!.text = obj["Id"] as? String
        
        // This adds the arrow to the right hand side.
        cell?.accessoryType = UITableViewCellAccessoryType.disclosureIndicator
        
        return cell!
    }
    //if let url = URL(string: "salesforce1://sObject/0010b00002CVSeTAAX/view") {
    // JS Code Example: window.location.replace("salesforce1://sObject/0010b00002CVSeTAAX/view");
    
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        // Get selected cell at Index
        let cell = tableView.cellForRow(at: indexPath)
        // Get selected cell detailText record ID
        let dataId : String = (cell!.detailTextLabel!.text)!
        // Comstruct URL scheme with record ID selected to Veiw
        let strURL : String = "salesforce1://sObject/" + dataId + "/view"
        if let url = URL(string: strURL) {
            // Open Account record in Salesforce Mobile
            
        }
    }
        
    
}
